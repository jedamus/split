/* -*- C -*- */
/* getlocaledir.c */
/* erzeugt Montag, 14. August 2023 08:33 (C) 2023 von Leander Jedamus */
/* modifiziert Montag, 07. Oktober 2024 06:45 von Leander Jedamus */
/* modifiziert Samstag, 02. September 2023 11:19 von Leander Jedamus */
/* modifiziert Donnerstag, 31. August 2023 06:09 von Leander Jedamus */
/* modifiziert Mittwoch, 30. August 2023 18:25 von Leander Jedamus */
/* modifiziert Montag, 28. August 2023 09:53 von Leander Jedamus */
/* modifiziert Dienstag, 15. August 2023 07:43 von Leander Jedamus */
/* modifiziert Montag, 14. August 2023 08:48 von Leander Jedamus */

#include <stdio.h>
#define __USE_MISC
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#if defined __linux__
  #include <linux/limits.h>
#elif defined __APPLE__
  #include <sys/syslimits.h>
#endif
#include "types.h"
#include "getlocaledir.h"

bool check_file(const char * path, const char * filename) {
  char * filename_with_path = (char *) malloc(PATH_MAX);

  sprintf(filename_with_path, "%s%c%s", path, PATH_DELIMITER, filename);

  if( access(filename_with_path, X_OK) != -1) {
    return true;
  } else {
    return false;
  }
}

void check_path(const char * path, char * localedir) {
  char * ptr;

  strncpy(localedir,path,PATH_MAX);

  ptr = (char *) strstr(localedir, PATH_DELIMITER2 "sbin");
  if( ptr == NULL) {
    ptr = (char *) strstr(localedir, PATH_DELIMITER2 "bin");
  }
  if( ptr != NULL) {
    sprintf(ptr,"%s", PATH_DELIMITER2 "share" PATH_DELIMITER2);
#ifdef DEBUG
    printf("1: %s\n", ptr);
#endif
  };
}

char *getlocaledir(CONST char * arg) {
  char   c;
  char * localedir = (char *) malloc(PATH_MAX);
  char * tmp;
  char * ptr;
  char * path;

  localedir = (char *) realpath(arg, localedir);
  if(localedir != NULL) {
#ifdef DEBUG
    printf("%s\n", localedir);
#endif
    ptr = strrchr(localedir, PATH_DELIMITER);

    if(ptr == NULL) {
#ifdef DEBUG
      printf("ptr == NULL\n");
#endif
    } else {
      ++ptr;
      *ptr = '\0';
    }

    strncat(localedir, "locale", PATH_MAX-6);
#ifdef DEBUG
    printf("%s\n", localedir);
#endif
    return localedir;
  } else {
    path = getenv("PATH");
#ifdef DEBUG
    printf("%s\n", path);
#endif
    while((ptr = strchr(path, PATH_SEPARATOR)) != NULL) {
      c = *ptr;
      *ptr = '\0';
      if (check_file(path, arg)) {
	tmp = (char *) malloc(PATH_MAX);
	strncpy(tmp,path,PATH_MAX);
	strncat(tmp, PATH_DELIMITER2 "locale", PATH_MAX-strlen(tmp));
	if (opendir(tmp) == NULL) {
	  check_path(path, tmp);
	  strcat(tmp, "locale");
	}
	return tmp;
      }
      *ptr = c;
      path = ++ptr;
    }
    if (check_file(path, arg)) {
      tmp = (char *) malloc(PATH_MAX);
      strncpy(tmp,path,PATH_MAX);
      strcat(tmp, PATH_DELIMITER2 "locale");
      if (opendir(tmp) == NULL) {
        check_path(path, tmp);
        strcat(tmp, "locale");
      }
      return tmp;
    }

    /*
    printf("error string: %s\n", strerror(errno));
    perror("realpath");
    */

    return NULL;
  }
}

/* vim:set cindent ai sw=2: */

