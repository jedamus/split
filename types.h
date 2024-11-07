/* -*- C -*- */
/* types.h */
/* erzeugt Freitag, 07. Juli 2023 12:41 (C) 2023 von Leander Jedamus */
/* modifiziert Montag, 07. Oktober 2024 06:46 von Leander Jedamus */
/* modifiziert Montag, 25. September 2023 07:38 von Leander Jedamus */
/* modifiziert Dienstag, 19. September 2023 18:30 von Leander Jedamus */
/* modifiziert Dienstag, 05. September 2023 08:18 von Leander Jedamus */
/* modifiziert Montag, 28. August 2023 18:03 von Leander Jedamus */
/* modifiziert Montag, 14. August 2023 08:49 von Leander Jedamus */
/* modifiziert Mittwoch, 26. Juli 2023 08:23 von Leander Jedamus */
/* modifiziert Dienstag, 18. Juli 2023 07:23 von Leander Jedamus */
/* modifiziert Montag, 10. Juli 2023 08:43 von Leander Jedamus */
/* modifiziert Freitag, 07. Juli 2023 12:58 von Leander Jedamus */

#ifndef TYPES_H
#define TYPES_H 1

#include <inttypes.h>
#include <limits.h>

typedef unsigned char byte;
typedef unsigned char uchar;

typedef unsigned int uint;
typedef signed int   sint;

typedef unsigned long long ull;
#define PRIull "llu"
#define SCNull "llu"
typedef signed long long   sll;
#define PRIsll "+lld"
#define SCNsll "lld"

/* typedef unsigned long int  ulint; */
typedef int_least32_t      ulint;
#define PRIulint           PRIdLEAST32
#define SCNulint           SCNdLEAST32

/* typedef signed long int    slint; */
typedef int_least32_t      slint;
#define PRIslint           PRIdLEAST32
#define SCNslint           SCNdLEAST32

typedef unsigned short int usint;
typedef signed short int   ssint;

typedef enum { false, true} bool;

#if defined __unix__ || defined __APPLE__
  #define PATH_SEPARATOR ':'
  #define PATH_DELIMITER '/'
  #define PATH_DELIMITER2 "/"
#else
  #define PATH_SEPARATOR ';'
  #define PATH_DELIMITER '\\'
  #define PATH_DELIMITER2 "\\"
#endif

#endif /* TYPES_H */

/* vim:set cindent ai sw=2 */

