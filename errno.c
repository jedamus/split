/* -*- C -*- */
/* errno.c */
/* erzeugt Donnerstag, 15. Februar 2024 13:20 (C) 2024 von Leander Jedamus */
/* modifiziert Sonntag, 03. März 2024 13:14 von Leander Jedamus */
/* modifiziert Freitag, 16. Februar 2024 16:31 von Leander Jedamus */
/* modifiziert Donnerstag, 15. Februar 2024 14:04 von Leander Jedamus */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>

#include "project.h"

#define DATETIMELEN 1024

void print_header(void) {
  time_t t = time(NULL);
  struct tm tp = *localtime(&t);
  char * name = PROJECT;
  char year[DATETIMELEN];
  char datetime[DATETIMELEN];

  strftime(year, DATETIMELEN, "%Y", &tp);
  strftime(datetime, DATETIMELEN, "%Y-%m-%d %H:%M:%S+0100", &tp);

  printf("# %s.\n", name);
  /* printf("# Copyright (C) %d Leander Jedamus\n", tp.tm_year + 1900); */
  printf("# Copyright (C) %s Leander Jedamus\n", year);
  printf("# This file is distributed under the same license as the %s package.\n", name);
  /* printf("# ljedamus@web.de, %d.\n", tp.tm_year + 1900); */
  printf("# ljedamus@web.de, %s.\n", year);
  printf("#\n");
  printf("msgid \"\"\n");
  printf("msgstr \"\"\n");
  printf("\"Project-Id-Version: %s 1.0\"\n", name);
  printf("\"Report-Msgid-Bugs-To: Leander Jedamus <ljedamus@web.de>\"\n");
  /* printf("\"POT-Creation-Date: %4d-%02d-%02d %02d:%02d:%02d+0100\"\n", tp.tm_year + 1900, tp.tm_mon + 1, tp.tm_mday, tp.tm_hour, tp.tm_min, tp.tm_sec); */
  printf("\"POT-Creation-Date: %s\"\n", datetime);
  /* printf("\"PO-Revision-Date: %4d-%02d-%02d %02d:%02d:%02d+0100\"\n", tp.tm_year + 1900, tp.tm_mon + 1, tp.tm_mday, tp.tm_hour, tp.tm_min, tp.tm_sec); */
  printf("\"PO-Revision-Date: %s\"\n", datetime);
  printf("\"Last-Translator: Automatically generated\"\n");
  printf("\"Language-Team: none\"\n");
  printf("\"Language: de\"\n");
  printf("\"MIME-Version: 1.0\"\n");
  printf("\"Content-Type: text/plain; charset=UTF-8\"\n");
  printf("\"Content-Transfer-Encoding: 8bit\"\n");
  printf("\"Plural-Forms: nplurals=2; plural=(n != 1);\"\n");
}

/*
#: main.c:90
#, c-format
msgid "Enter a number: "
msgstr "Geben Sie eine Zahl ein: "

#: main.c:92
#, c-format
msgid "Input error.\n"
msgstr "Fehlerhafte Eingabe.\n"

#: main.c:103
#, c-format
msgid "Please press 'q' to end program!\n"
msgstr "Drücken Sie bitte 'q', um das Programm zu beenden!\n"
*/

int main(int argc, char * argv[]) {
  int i;

  /* print_header(); */

  for (i = 0; i < 134; ++i) {
    /* printf("%d %s\n", i, strerror(i)); */
    printf("  printf(\"%%s\\n\", _(\"%s\"));\n", strerror(i));
    /*
    printf("\n");
    printf("#%03d\n", i);
    printf("msgid \"%s\"\n", strerror(i));
    printf("msgstr \"%s\"\n", strerror(i));
    */
  };

  return EXIT_SUCCESS;
}

/* vim:set cindent ai sw=2: */

