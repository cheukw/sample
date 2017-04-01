# 1 "event.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "event.c"
# 40 "event.c"
# 1 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 1 3 4
# 149 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 3 4

# 149 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 3 4
typedef int ptrdiff_t;
# 216 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 3 4
typedef unsigned int size_t;
# 41 "event.c" 2
# 1 "c:\\devel\\mingw\\include\\stdlib.h" 1 3
# 34 "c:\\devel\\mingw\\include\\stdlib.h" 3
       
# 35 "c:\\devel\\mingw\\include\\stdlib.h" 3
# 49 "c:\\devel\\mingw\\include\\stdlib.h" 3
# 1 "c:\\devel\\mingw\\include\\_mingw.h" 1 3
# 55 "c:\\devel\\mingw\\include\\_mingw.h" 3
       
# 56 "c:\\devel\\mingw\\include\\_mingw.h" 3
# 66 "c:\\devel\\mingw\\include\\_mingw.h" 3
# 1 "c:\\devel\\mingw\\include\\msvcrtver.h" 1 3
# 35 "c:\\devel\\mingw\\include\\msvcrtver.h" 3
       
# 36 "c:\\devel\\mingw\\include\\msvcrtver.h" 3
# 67 "c:\\devel\\mingw\\include\\_mingw.h" 2 3






# 1 "c:\\devel\\mingw\\include\\w32api.h" 1 3
# 35 "c:\\devel\\mingw\\include\\w32api.h" 3
       
# 36 "c:\\devel\\mingw\\include\\w32api.h" 3
# 59 "c:\\devel\\mingw\\include\\w32api.h" 3
# 1 "c:\\devel\\mingw\\include\\sdkddkver.h" 1 3
# 35 "c:\\devel\\mingw\\include\\sdkddkver.h" 3
       
# 36 "c:\\devel\\mingw\\include\\sdkddkver.h" 3
# 60 "c:\\devel\\mingw\\include\\w32api.h" 2 3
# 74 "c:\\devel\\mingw\\include\\_mingw.h" 2 3
# 50 "c:\\devel\\mingw\\include\\stdlib.h" 2 3





# 1 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 1 3 4
# 56 "c:\\devel\\mingw\\include\\stdlib.h" 2 3
# 90 "c:\\devel\\mingw\\include\\stdlib.h" 3
extern "C" {
# 99 "c:\\devel\\mingw\\include\\stdlib.h" 3
extern int _argc;
extern char **_argv;




extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) int *__p___argc(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) char ***__p___argv(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t ***__p___wargv(void);
# 142 "c:\\devel\\mingw\\include\\stdlib.h" 3
   extern __attribute__((__dllimport__)) int __mb_cur_max;
# 166 "c:\\devel\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int *_errno(void);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int *__doserrno(void);







extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) char ***__p__environ(void);

extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t ***__p__wenviron(void);
# 202 "c:\\devel\\mingw\\include\\stdlib.h" 3
extern __attribute__((__dllimport__)) int _sys_nerr;
# 227 "c:\\devel\\mingw\\include\\stdlib.h" 3
extern __attribute__((__dllimport__)) char *_sys_errlist[];
# 238 "c:\\devel\\mingw\\include\\stdlib.h" 3
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int *__p__osver(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int *__p__winver(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int *__p__winmajor(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int *__p__winminor(void);
# 250 "c:\\devel\\mingw\\include\\stdlib.h" 3
extern __attribute__((__dllimport__)) unsigned int _osver;
extern __attribute__((__dllimport__)) unsigned int _winver;
extern __attribute__((__dllimport__)) unsigned int _winmajor;
extern __attribute__((__dllimport__)) unsigned int _winminor;
# 289 "c:\\devel\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char **__p__pgmptr(void);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t **__p__wpgmptr(void);
# 325 "c:\\devel\\mingw\\include\\stdlib.h" 3
extern __attribute__((__dllimport__)) int _fmode;
# 335 "c:\\devel\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int atoi (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long atol (const char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double strtod (const char *, char **);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double atof (const char *);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double _wtof (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wtoi (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long _wtol (const wchar_t *);
# 378 "c:\\devel\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__))
float strtof (const char *__restrict__, char **__restrict__);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
long double strtold (const char *__restrict__, char **__restrict__);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long strtol (const char *, char **, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned long strtoul (const char *, char **, int);







 __attribute__((__cdecl__)) __attribute__((__nothrow__))
long wcstol (const wchar_t *, wchar_t **, int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
unsigned long wcstoul (const wchar_t *, wchar_t **, int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double wcstod (const wchar_t *, wchar_t **);





__attribute__((__cdecl__)) __attribute__((__nothrow__))
float wcstof (const wchar_t *__restrict__, wchar_t **__restrict__);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
long double wcstold (const wchar_t *__restrict__, wchar_t **__restrict__);
# 451 "c:\\devel\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wgetenv (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wputenv (const wchar_t *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _wsearchenv (const wchar_t *, const wchar_t *, wchar_t *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wsystem (const wchar_t *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _wmakepath (wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *,
    const wchar_t *
  );

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _wsplitpath (const wchar_t *, wchar_t *, wchar_t *, wchar_t *, wchar_t *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
wchar_t *_wfullpath (wchar_t *, const wchar_t *, size_t);





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcstombs (char *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wctomb (char *, wchar_t);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int mblen (const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t mbstowcs (wchar_t *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int mbtowc (wchar_t *, const char *, size_t);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int rand (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void srand (unsigned int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *calloc (size_t, size_t) __attribute__((__malloc__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *malloc (size_t) __attribute__((__malloc__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *realloc (void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void free (void *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void abort (void) __attribute__((__noreturn__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void exit (int) __attribute__((__noreturn__));



int __attribute__((__cdecl__)) __attribute__((__nothrow__)) atexit (void (*)(void));

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int system (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *getenv (const char *);






 __attribute__((__cdecl__)) void *bsearch
(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

 __attribute__((__cdecl__)) void qsort
(void *, size_t, size_t, int (*)(const void *, const void *));

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int abs (int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long labs (long) __attribute__((__const__));
# 519 "c:\\devel\\mingw\\include\\stdlib.h" 3
typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) div_t div (int, int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) ldiv_t ldiv (long, long) __attribute__((__const__));






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _exit (int) __attribute__((__noreturn__));





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long long _atoi64 (const char *);
# 545 "c:\\devel\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _beep (unsigned int, unsigned int) __attribute__((__deprecated__));

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _seterrormode (int) __attribute__((__deprecated__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _sleep (unsigned long) __attribute__((__deprecated__));



typedef int (* _onexit_t)(void);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) _onexit_t _onexit( _onexit_t );

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _putenv (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _searchenv (const char *, const char *, char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_ecvt (double, int, int *, int *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_fcvt (double, int, int *, int *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_gcvt (double, int, char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _makepath (char *, const char *, const char *, const char *, const char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _splitpath (const char *, char *, char *, char *, char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_fullpath (char*, const char*, size_t);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_itoa (int, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_ltoa (long, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_ultoa(unsigned long, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_itow (int, wchar_t *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_ltow (long, wchar_t *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_ultow (unsigned long, wchar_t *, int);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* _i64toa (long long, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* _ui64toa (unsigned long long, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long long _wtoi64 (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t* _i64tow (long long, wchar_t *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t* _ui64tow (unsigned long long, wchar_t *, int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int (_rotl)(unsigned int, int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int (_rotr)(unsigned int, int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned long (_lrotl)(unsigned long, int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned long (_lrotr)(unsigned long, int) __attribute__((__const__));

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _set_error_mode (int);
# 628 "c:\\devel\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int putenv (const char*);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void searchenv (const char*, const char*, char*);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* itoa (int, char*, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* ltoa (long, char*, int);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* ecvt (double, int, int*, int*);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* fcvt (double, int, int*, int*);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* gcvt (double, int, char*);
# 649 "c:\\devel\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) void _Exit(int) __attribute__((__noreturn__));






typedef struct { long long quot, rem; } lldiv_t;
__attribute__((__cdecl__)) __attribute__((__nothrow__)) lldiv_t lldiv (long long, long long) __attribute__((__const__));

__attribute__((__cdecl__)) __attribute__((__nothrow__)) long long llabs (long long);
# 670 "c:\\devel\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__))
long long strtoll (const char *__restrict__, char **__restrict, int);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
unsigned long long strtoull (const char *__restrict__, char **__restrict__, int);





__attribute__((__cdecl__)) __attribute__((__nothrow__)) long long atoll (const char *);
# 726 "c:\\devel\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) long long wtoll (const wchar_t *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) char *lltoa (long long, char *, int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) char *ulltoa (unsigned long long , char *, int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) wchar_t *lltow (long long, wchar_t *, int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) wchar_t *ulltow (unsigned long long, wchar_t *, int);
# 766 "c:\\devel\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int mkstemp (char *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int __mingw_mkstemp (int, char *);
# 808 "c:\\devel\\mingw\\include\\stdlib.h" 3
inline __attribute__((__always_inline__))
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int mkstemp (char *__filename_template)
{ return __mingw_mkstemp( 0, __filename_template ); }
# 819 "c:\\devel\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *mkdtemp (char *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *__mingw_mkdtemp (char *);

inline __attribute__((__always_inline__))
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *mkdtemp (char *__dirname_template)
{ return __mingw_mkdtemp( __dirname_template ); }




}
# 42 "event.c" 2
# 1 "c:\\devel\\mingw\\include\\assert.h" 1 3
# 23 "c:\\devel\\mingw\\include\\assert.h" 3
extern "C" {
# 38 "c:\\devel\\mingw\\include\\assert.h" 3
 void __attribute__((__cdecl__)) __attribute__((__nothrow__)) _assert (const char*, const char*, int) __attribute__((__noreturn__));
# 48 "c:\\devel\\mingw\\include\\assert.h" 3
}
# 43 "event.c" 2




# 1 "event.h" 1
# 46 "event.h"
# 1 "ev.h" 1
# 55 "ev.h"

# 55 "ev.h"
extern "C" {
# 153 "ev.h"
typedef double ev_tstamp;

# 1 "c:\\devel\\mingw\\include\\string.h" 1 3
# 34 "c:\\devel\\mingw\\include\\string.h" 3
       
# 35 "c:\\devel\\mingw\\include\\string.h" 3
# 53 "c:\\devel\\mingw\\include\\string.h" 3
# 1 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 1 3 4
# 54 "c:\\devel\\mingw\\include\\string.h" 2 3
# 62 "c:\\devel\\mingw\\include\\string.h" 3
# 1 "c:\\devel\\mingw\\include\\strings.h" 1 3
# 33 "c:\\devel\\mingw\\include\\strings.h" 3
       
# 34 "c:\\devel\\mingw\\include\\strings.h" 3
# 59 "c:\\devel\\mingw\\include\\strings.h" 3
# 1 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 1 3 4
# 60 "c:\\devel\\mingw\\include\\strings.h" 2 3


# 61 "c:\\devel\\mingw\\include\\strings.h" 3
extern "C" {

int __attribute__((__cdecl__)) __attribute__((__nothrow__)) strcasecmp( const char *, const char * );
int __attribute__((__cdecl__)) __attribute__((__nothrow__)) strncasecmp( const char *, const char *, size_t );
# 97 "c:\\devel\\mingw\\include\\strings.h" 3
}
# 63 "c:\\devel\\mingw\\include\\string.h" 2 3


extern "C" {




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memchr (const void *, int, size_t) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int memcmp (const void *, const void *, size_t) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memcpy (void *, const void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memmove (void *, const void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memset (void *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strcat (char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strchr (const char *, int) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strcmp (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strcoll (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strcpy (char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strcspn (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strerror (int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strlen (const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strncat (char *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strncmp (const char *, const char *, size_t) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strncpy (char *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strpbrk (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strrchr (const char *, int) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strspn (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strstr (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strtok (char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strxfrm (char *, const char *, size_t);





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strerror (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *_memccpy (void *, const void *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _memicmp (const void *, const void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strdup (const char *) __attribute__((__malloc__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _strcmpi (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _stricoll (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strlwr (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strnset (char *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strrev (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strset (char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strupr (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _swab (const char *, char *, size_t);
# 125 "c:\\devel\\mingw\\include\\string.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _strncoll(const char *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _strnicoll(const char *, const char *, size_t);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memccpy (void *, const void *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int memicmp (const void *, const void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strdup (const char *) __attribute__((__malloc__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strcmpi (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int stricmp (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int stricoll (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strlwr (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strnicmp (const char *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strnset (char *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strrev (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strset (char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strupr (char *);





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void swab (const char *, char *, size_t);
# 165 "c:\\devel\\mingw\\include\\string.h" 3
# 1 "c:\\devel\\mingw\\include\\wchar.h" 1 3
# 35 "c:\\devel\\mingw\\include\\wchar.h" 3
       
# 36 "c:\\devel\\mingw\\include\\wchar.h" 3
# 392 "c:\\devel\\mingw\\include\\wchar.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcscat (wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcschr (const wchar_t *, wchar_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcscmp (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcscoll (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcscpy (wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcscspn (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcslen (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsncat (wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcsncmp (const wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsncpy (wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcspbrk (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsrchr (const wchar_t *, wchar_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcsspn (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsstr (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcstok (wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcsxfrm (wchar_t *, const wchar_t *, size_t);




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsdup (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsicmp (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsicoll (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcslwr (wchar_t*);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsnicmp (const wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsnset (wchar_t *, wchar_t, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsrev (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsset (wchar_t *, wchar_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsupr (wchar_t *);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsncoll (const wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsnicoll (const wchar_t *, const wchar_t *, size_t);
# 445 "c:\\devel\\mingw\\include\\wchar.h" 3
int __attribute__((__cdecl__)) __attribute__((__nothrow__)) wcscmpi (const wchar_t *, const wchar_t *);
# 457 "c:\\devel\\mingw\\include\\wchar.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsdup (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcsicmp (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcsicoll (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcslwr (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcsnicmp (const wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsnset (wchar_t *, wchar_t, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsrev (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsset (wchar_t *, wchar_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsupr (wchar_t *);
# 166 "c:\\devel\\mingw\\include\\string.h" 2 3
# 187 "c:\\devel\\mingw\\include\\string.h" 3
extern size_t __mingw_strnlen (const char *, size_t);


inline __attribute__((__always_inline__)) size_t strnlen (const char *__text, size_t __maxlen)
{ return __mingw_strnlen (__text, __maxlen); }





}
# 156 "ev.h" 2


# 1 "c:\\devel\\mingw\\include\\signal.h" 1 3
# 46 "c:\\devel\\mingw\\include\\signal.h" 3
typedef int sig_atomic_t;
# 60 "c:\\devel\\mingw\\include\\signal.h" 3
typedef void (*__p_sig_fn_t)(int);
# 75 "c:\\devel\\mingw\\include\\signal.h" 3
extern "C" {
# 84 "c:\\devel\\mingw\\include\\signal.h" 3
 __p_sig_fn_t __attribute__((__cdecl__)) __attribute__((__nothrow__)) signal(int, __p_sig_fn_t);




 int __attribute__((__cdecl__)) __attribute__((__nothrow__)) raise (int);


}
# 159 "ev.h" 2





# 1 "c:\\devel\\mingw\\include\\time.h" 1 3
# 33 "c:\\devel\\mingw\\include\\time.h" 3
       
# 34 "c:\\devel\\mingw\\include\\time.h" 3
# 45 "c:\\devel\\mingw\\include\\time.h" 3
# 1 "c:\\devel\\mingw\\include\\sys\\types.h" 1 3
# 34 "c:\\devel\\mingw\\include\\sys\\types.h" 3
       
# 35 "c:\\devel\\mingw\\include\\sys\\types.h" 3
# 139 "c:\\devel\\mingw\\include\\sys\\types.h" 3
  typedef long __time32_t;
  typedef long long __time64_t;
# 149 "c:\\devel\\mingw\\include\\sys\\types.h" 3
   typedef __time32_t time_t;
# 46 "c:\\devel\\mingw\\include\\time.h" 2 3
# 102 "c:\\devel\\mingw\\include\\time.h" 3
struct timespec
{







  __time64_t tv_sec;
  long tv_nsec;
};


struct __mingw32_expanded_timespec
{





  union
  {



    __time64_t __tv64_sec;
    __time32_t __tv32_sec;
    time_t tv_sec;
  };
  long tv_nsec;
};
# 142 "c:\\devel\\mingw\\include\\time.h" 3
extern "C" {

inline __attribute__((__always_inline__))







struct __mingw32_expanded_timespec *mingw_timespec( struct timespec *__tv )
{ return (struct __mingw32_expanded_timespec *)(__tv); }

}
# 165 "c:\\devel\\mingw\\include\\time.h" 3
# 1 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 1 3 4
# 166 "c:\\devel\\mingw\\include\\time.h" 2 3




typedef long clock_t;

struct tm
{




  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};

extern "C" {

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) clock_t clock (void);
# 201 "c:\\devel\\mingw\\include\\time.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) time_t time (time_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double difftime (time_t, time_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) time_t mktime (struct tm *);
# 215 "c:\\devel\\mingw\\include\\time.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *asctime (const struct tm *);





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *ctime (const time_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) struct tm *gmtime (const time_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) struct tm *localtime (const time_t *);


 __attribute__((__cdecl__)) __attribute__((__nothrow__))
size_t strftime (char *, size_t, const char *, const struct tm *);


extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _tzset (void);


extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) void tzset (void);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strdate (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strtime (char *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) __time64_t _time64( __time64_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) __time64_t _mktime64 (struct tm *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_ctime64 (const __time64_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) struct tm *_gmtime64 (const __time64_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) struct tm *_localtime64 (const __time64_t *);
# 331 "c:\\devel\\mingw\\include\\time.h" 3
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) int *__p__daylight (void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) long *__p__timezone (void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) char **__p__tzname (void);

extern __attribute__((__dllimport__)) int _daylight;
extern __attribute__((__dllimport__)) long _timezone;
extern __attribute__((__dllimport__)) char *_tzname[2];
# 368 "c:\\devel\\mingw\\include\\time.h" 3
extern __attribute__((__dllimport__)) int daylight;
extern __attribute__((__dllimport__)) long timezone;
extern __attribute__((__dllimport__)) char *tzname[2];
# 394 "c:\\devel\\mingw\\include\\time.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__))
int nanosleep( const struct timespec *, struct timespec * );
# 415 "c:\\devel\\mingw\\include\\time.h" 3
}
# 427 "c:\\devel\\mingw\\include\\time.h" 3
extern "C" {


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wasctime (const struct tm *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wstrdate (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wstrtime (wchar_t *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wctime64 (const __time64_t *);
# 453 "c:\\devel\\mingw\\include\\time.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wctime (const time_t *);
# 482 "c:\\devel\\mingw\\include\\time.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__))
size_t wcsftime (wchar_t *, size_t, const wchar_t *, const struct tm *);

}
# 165 "ev.h" 2
# 1 "c:\\devel\\mingw\\include\\sys\\types.h" 1 3
# 34 "c:\\devel\\mingw\\include\\sys\\types.h" 3
       
# 35 "c:\\devel\\mingw\\include\\sys\\types.h" 3
# 62 "c:\\devel\\mingw\\include\\sys\\types.h" 3
  typedef long __off32_t;




  typedef __off32_t _off_t;







  typedef _off_t off_t;
# 91 "c:\\devel\\mingw\\include\\sys\\types.h" 3
  typedef long long __off64_t;






  typedef __off64_t off64_t;
# 115 "c:\\devel\\mingw\\include\\sys\\types.h" 3
  typedef int _ssize_t;







  typedef _ssize_t ssize_t;
# 174 "c:\\devel\\mingw\\include\\sys\\types.h" 3
# 1 "c:\\devel\\mingw\\lib\\gcc\\mingw32\\5.3.0\\include\\stddef.h" 1 3 4
# 175 "c:\\devel\\mingw\\include\\sys\\types.h" 2 3
# 184 "c:\\devel\\mingw\\include\\sys\\types.h" 3
typedef unsigned int _dev_t;
# 195 "c:\\devel\\mingw\\include\\sys\\types.h" 3
typedef short _ino_t;
typedef unsigned short _mode_t;
typedef int _pid_t;
typedef int _sigset_t;
# 207 "c:\\devel\\mingw\\include\\sys\\types.h" 3
typedef _dev_t dev_t;
typedef _ino_t ino_t;
typedef _mode_t mode_t;
typedef _pid_t pid_t;
typedef _sigset_t sigset_t;


typedef long long fpos64_t;






typedef unsigned long useconds_t __attribute__((__deprecated__));
# 166 "ev.h" 2

# 1 "c:\\devel\\mingw\\include\\sys\\stat.h" 1 3
# 34 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
       
# 35 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
# 127 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
        
# 173 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
struct _stat { _dev_t st_dev; _ino_t st_ino; _mode_t st_mode; short st_nlink; short st_uid; short st_gid; _dev_t st_rdev; _off_t st_size; time_t st_atime; time_t st_mtime; time_t st_ctime; };






struct stat { _dev_t st_dev; _ino_t st_ino; _mode_t st_mode; short st_nlink; short st_uid; short st_gid; _dev_t st_rdev; _off_t st_size; time_t st_atime; time_t st_mtime; time_t st_ctime; };







struct _stati64 { _dev_t st_dev; _ino_t st_ino; _mode_t st_mode; short st_nlink; short st_uid; short st_gid; _dev_t st_rdev; __off64_t st_size; time_t st_atime; time_t st_mtime; time_t st_ctime; };






struct __stat64 { _dev_t st_dev; _ino_t st_ino; _mode_t st_mode; short st_nlink; short st_uid; short st_gid; _dev_t st_rdev; __off64_t st_size; __time64_t st_atime; __time64_t st_mtime; __time64_t st_ctime; };
# 218 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
extern "C" {





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _umask (int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _chmod (const char *, int);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _fstat (int, struct _stat *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _stat (const char *, struct _stat *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int umask (int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int chmod (const char *, int);
# 250 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fstat (int, struct stat *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int stat (const char *, struct stat *);
# 260 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _fstati64 (int, struct _stati64 *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _stati64 (const char *, struct _stati64 *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _fstat64 (int, struct __stat64 *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _stat64 (const char *, struct __stat64 *);
# 352 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wstat(const wchar_t *, struct _stat *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wstati64 (const wchar_t *, struct _stati64 *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wstat64 (const wchar_t *, struct __stat64 *);
# 398 "c:\\devel\\mingw\\include\\sys\\stat.h" 3
}
# 168 "ev.h" 2





# 172 "ev.h"
struct ev_loop;
# 217 "ev.h"
enum {
  EV_UNDEF = (int)0xFFFFFFFF,
  EV_NONE = 0x00,
  EV_READ = 0x01,
  EV_WRITE = 0x02,
  EV__IOFDSET = 0x80,
  EV_IO = EV_READ,
  EV_TIMER = 0x00000100,

  EV_TIMEOUT = EV_TIMER,

  EV_PERIODIC = 0x00000200,
  EV_SIGNAL = 0x00000400,
  EV_CHILD = 0x00000800,
  EV_STAT = 0x00001000,
  EV_IDLE = 0x00002000,
  EV_PREPARE = 0x00004000,
  EV_CHECK = 0x00008000,
  EV_EMBED = 0x00010000,
  EV_FORK = 0x00020000,
  EV_CLEANUP = 0x00040000,
  EV_ASYNC = 0x00080000,
  EV_CUSTOM = 0x01000000,
  EV_ERROR = (int)0x80000000
};
# 298 "ev.h"
typedef struct ev_watcher
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_watcher *w, int revents);
} ev_watcher;


typedef struct ev_watcher_list
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_watcher_list *w, int revents); struct ev_watcher_list *next;
} ev_watcher_list;


typedef struct ev_watcher_time
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_watcher_time *w, int revents); ev_tstamp at;
} ev_watcher_time;



typedef struct ev_io
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_io *w, int revents); struct ev_watcher_list *next;

  int fd;
  int events;
} ev_io;



typedef struct ev_timer
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_timer *w, int revents); ev_tstamp at;

  ev_tstamp repeat;
} ev_timer;



typedef struct ev_periodic
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_periodic *w, int revents); ev_tstamp at;

  ev_tstamp offset;
  ev_tstamp interval;
  ev_tstamp (*reschedule_cb)(struct ev_periodic *w, ev_tstamp now) throw ();
} ev_periodic;



typedef struct ev_signal
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_signal *w, int revents); struct ev_watcher_list *next;

  int signum;
} ev_signal;




typedef struct ev_child
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_child *w, int revents); struct ev_watcher_list *next;

  int flags;
  int pid;
  int rpid;
  int rstatus;
} ev_child;




typedef struct _stati64 ev_statdata;






typedef struct ev_stat
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_stat *w, int revents); struct ev_watcher_list *next;

  ev_timer timer;
  ev_tstamp interval;
  const char *path;
  ev_statdata prev;
  ev_statdata attr;

  int wd;
} ev_stat;





typedef struct ev_idle
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_idle *w, int revents);
} ev_idle;





typedef struct ev_prepare
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_prepare *w, int revents);
} ev_prepare;



typedef struct ev_check
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_check *w, int revents);
} ev_check;




typedef struct ev_fork
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_fork *w, int revents);
} ev_fork;





typedef struct ev_cleanup
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_cleanup *w, int revents);
} ev_cleanup;





typedef struct ev_embed
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_embed *w, int revents);

  struct ev_loop *other;
  ev_io io;
  ev_prepare prepare;
  ev_check check;
  ev_timer timer;
  ev_periodic periodic;
  ev_idle idle;
  ev_fork fork;

  ev_cleanup cleanup;

} ev_embed;





typedef struct ev_async
{
  int active; int pending; int priority; void *data; void (*cb)(struct ev_loop *loop, struct ev_async *w, int revents);

  sig_atomic_t volatile sent;
} ev_async;





union ev_any_watcher
{
  struct ev_watcher w;
  struct ev_watcher_list wl;

  struct ev_io io;
  struct ev_timer timer;
  struct ev_periodic periodic;
  struct ev_signal signal;
  struct ev_child child;

  struct ev_stat stat;


  struct ev_idle idle;

  struct ev_prepare prepare;
  struct ev_check check;

  struct ev_fork fork;


  struct ev_cleanup cleanup;


  struct ev_embed embed;


  struct ev_async async;

};


enum {

  EVFLAG_AUTO = 0x00000000U,

  EVFLAG_NOENV = 0x01000000U,
  EVFLAG_FORKCHECK = 0x02000000U,

  EVFLAG_NOINOTIFY = 0x00100000U,

  EVFLAG_NOSIGFD = 0,

  EVFLAG_SIGNALFD = 0x00200000U,
  EVFLAG_NOSIGMASK = 0x00400000U
};


enum {
  EVBACKEND_SELECT = 0x00000001U,
  EVBACKEND_POLL = 0x00000002U,
  EVBACKEND_EPOLL = 0x00000004U,
  EVBACKEND_KQUEUE = 0x00000008U,
  EVBACKEND_DEVPOLL = 0x00000010U,
  EVBACKEND_PORT = 0x00000020U,
  EVBACKEND_ALL = 0x0000003FU,
  EVBACKEND_MASK = 0x0000FFFFU
};


extern int ev_version_major (void) throw ();
extern int ev_version_minor (void) throw ();

extern unsigned int ev_supported_backends (void) throw ();
extern unsigned int ev_recommended_backends (void) throw ();
extern unsigned int ev_embeddable_backends (void) throw ();

extern ev_tstamp ev_time (void) throw ();
extern void ev_sleep (ev_tstamp delay) throw ();







extern void ev_set_allocator (void *(*cb)(void *ptr, long size) throw ()) throw ();





extern void ev_set_syserr_cb (void (*cb)(const char *msg) throw ()) throw ();





extern struct ev_loop *ev_default_loop (unsigned int flags = 0) throw ();





static inline struct ev_loop *
ev_default_loop_uc_ (void) throw ()
{
  extern struct ev_loop *ev_default_loop_ptr;

  return ev_default_loop_ptr;
}

static inline int
ev_is_default_loop (struct ev_loop *loop) throw ()
{
  return loop == ev_default_loop_uc_ ();
}


extern struct ev_loop *ev_loop_new (unsigned int flags = 0) throw ();

extern ev_tstamp ev_now (struct ev_loop *loop) throw ();
# 604 "ev.h"
extern void ev_loop_destroy (struct ev_loop *loop);





extern void ev_loop_fork (struct ev_loop *loop) throw ();

extern unsigned int ev_backend (struct ev_loop *loop) throw ();

extern void ev_now_update (struct ev_loop *loop) throw ();
# 626 "ev.h"
enum {
  EVRUN_NOWAIT = 1,
  EVRUN_ONCE = 2
};


enum {
  EVBREAK_CANCEL = 0,
  EVBREAK_ONE = 1,
  EVBREAK_ALL = 2
};


extern int ev_run (struct ev_loop *loop, int flags = 0);
extern void ev_break (struct ev_loop *loop, int how = EVBREAK_ONE) throw ();






extern void ev_ref (struct ev_loop *loop) throw ();
extern void ev_unref (struct ev_loop *loop) throw ();





extern void ev_once (struct ev_loop *loop, int fd, int events, ev_tstamp timeout, void (*cb)(int revents, void *arg), void *arg) throw ();


extern unsigned int ev_iteration (struct ev_loop *loop) throw ();
extern unsigned int ev_depth (struct ev_loop *loop) throw ();
extern void ev_verify (struct ev_loop *loop) throw ();

extern void ev_set_io_collect_interval (struct ev_loop *loop, ev_tstamp interval) throw ();
extern void ev_set_timeout_collect_interval (struct ev_loop *loop, ev_tstamp interval) throw ();


extern void ev_set_userdata (struct ev_loop *loop, void *data) throw ();
extern void *ev_userdata (struct ev_loop *loop) throw ();
typedef void (*ev_loop_callback)(struct ev_loop *loop);
extern void ev_set_invoke_pending_cb (struct ev_loop *loop, ev_loop_callback invoke_pending_cb) throw ();

extern void ev_set_loop_release_cb (struct ev_loop *loop, void (*release)(struct ev_loop *loop) throw (), void (*acquire)(struct ev_loop *loop) throw ()) throw ();

extern unsigned int ev_pending_count (struct ev_loop *loop) throw ();
extern void ev_invoke_pending (struct ev_loop *loop);




extern void ev_suspend (struct ev_loop *loop) throw ();
extern void ev_resume (struct ev_loop *loop) throw ();
# 747 "ev.h"
extern void ev_feed_event (struct ev_loop *loop, void *w, int revents) throw ();
extern void ev_feed_fd_event (struct ev_loop *loop, int fd, int revents) throw ();

extern void ev_feed_signal (int signum) throw ();
extern void ev_feed_signal_event (struct ev_loop *loop, int signum) throw ();

extern void ev_invoke (struct ev_loop *loop, void *w, int revents);
extern int ev_clear_pending (struct ev_loop *loop, void *w) throw ();

extern void ev_io_start (struct ev_loop *loop, ev_io *w) throw ();
extern void ev_io_stop (struct ev_loop *loop, ev_io *w) throw ();

extern void ev_timer_start (struct ev_loop *loop, ev_timer *w) throw ();
extern void ev_timer_stop (struct ev_loop *loop, ev_timer *w) throw ();

extern void ev_timer_again (struct ev_loop *loop, ev_timer *w) throw ();

extern ev_tstamp ev_timer_remaining (struct ev_loop *loop, ev_timer *w) throw ();


extern void ev_periodic_start (struct ev_loop *loop, ev_periodic *w) throw ();
extern void ev_periodic_stop (struct ev_loop *loop, ev_periodic *w) throw ();
extern void ev_periodic_again (struct ev_loop *loop, ev_periodic *w) throw ();




extern void ev_signal_start (struct ev_loop *loop, ev_signal *w) throw ();
extern void ev_signal_stop (struct ev_loop *loop, ev_signal *w) throw ();
# 785 "ev.h"
extern void ev_stat_start (struct ev_loop *loop, ev_stat *w) throw ();
extern void ev_stat_stop (struct ev_loop *loop, ev_stat *w) throw ();
extern void ev_stat_stat (struct ev_loop *loop, ev_stat *w) throw ();



extern void ev_idle_start (struct ev_loop *loop, ev_idle *w) throw ();
extern void ev_idle_stop (struct ev_loop *loop, ev_idle *w) throw ();



extern void ev_prepare_start (struct ev_loop *loop, ev_prepare *w) throw ();
extern void ev_prepare_stop (struct ev_loop *loop, ev_prepare *w) throw ();



extern void ev_check_start (struct ev_loop *loop, ev_check *w) throw ();
extern void ev_check_stop (struct ev_loop *loop, ev_check *w) throw ();



extern void ev_fork_start (struct ev_loop *loop, ev_fork *w) throw ();
extern void ev_fork_stop (struct ev_loop *loop, ev_fork *w) throw ();



extern void ev_cleanup_start (struct ev_loop *loop, ev_cleanup *w) throw ();
extern void ev_cleanup_stop (struct ev_loop *loop, ev_cleanup *w) throw ();




extern void ev_embed_start (struct ev_loop *loop, ev_embed *w) throw ();
extern void ev_embed_stop (struct ev_loop *loop, ev_embed *w) throw ();
extern void ev_embed_sweep (struct ev_loop *loop, ev_embed *w) throw ();



extern void ev_async_start (struct ev_loop *loop, ev_async *w) throw ();
extern void ev_async_stop (struct ev_loop *loop, ev_async *w) throw ();
extern void ev_async_send (struct ev_loop *loop, ev_async *w) throw ();
# 835 "ev.h"
    static inline void ev_loop (struct ev_loop *loop, int flags) { ev_run (loop, flags); }
    static inline void ev_unloop (struct ev_loop *loop, int how ) { ev_break (loop, how ); }
    static inline void ev_default_destroy (void) { ev_loop_destroy (ev_default_loop (0)); }
    static inline void ev_default_fork (void) { ev_loop_fork (ev_default_loop (0)); }

      static inline unsigned int ev_loop_count (struct ev_loop *loop) { return ev_iteration (loop); }
      static inline unsigned int ev_loop_depth (struct ev_loop *loop) { return ev_depth (loop); }
      static inline void ev_loop_verify (struct ev_loop *loop) { ev_verify (loop); }
# 851 "ev.h"
}
# 47 "event.h" 2
# 60 "event.h"
extern "C" {




# 1 "c:\\devel\\mingw\\include\\time.h" 1 3
# 66 "event.h" 2
# 1 "c:\\devel\\mingw\\include\\sys\\time.h" 1 3


# 1 "c:\\devel\\mingw\\include\\time.h" 1 3
# 4 "c:\\devel\\mingw\\include\\sys\\time.h" 2 3



# 6 "c:\\devel\\mingw\\include\\sys\\time.h" 3
extern "C" {




struct timeval {
  long tv_sec;
  long tv_usec;
};
# 26 "c:\\devel\\mingw\\include\\sys\\time.h" 3
struct timezone
{
  int tz_minuteswest;
  int tz_dsttime;
};
# 39 "c:\\devel\\mingw\\include\\sys\\time.h" 3
int __attribute__((__cdecl__)) __attribute__((__nothrow__)) gettimeofday(struct timeval *__restrict__,
    void *__restrict__ );


}
# 67 "event.h" 2



# 69 "event.h"
struct event_base;
# 78 "event.h"
typedef void (*event_callback_fn)(int, short, void *);

struct event
{

  union {
    struct ev_io io;
    struct ev_signal sig;
  } iosig;
  struct ev_timer to;


  struct event_base *ev_base;
  event_callback_fn ev_callback;
  void *ev_arg;
  int ev_fd;
  int ev_pri;
  int ev_res;
  int ev_flags;
  short ev_events;
};

event_callback_fn event_get_callback (const struct event *ev);
# 130 "event.h"
const char *event_get_version (void);
const char *event_get_method (void);

void *event_init (void);
void event_base_free (struct event_base *base);


int event_loop (int);
int event_loopexit (struct timeval *tv);
int event_dispatch (void);





typedef void (*event_log_cb)(int severity, const char *msg);
void event_set_log_callback(event_log_cb cb);

void event_set (struct event *ev, int fd, short events, void (*cb)(int, short, void *), void *arg);
int event_once (int fd, short events, void (*cb)(int, short, void *), void *arg, struct timeval *tv);

int event_add (struct event *ev, struct timeval *tv);
int event_del (struct event *ev);
void event_active (struct event *ev, int res, short ncalls);

int event_pending (struct event *ev, short, struct timeval *tv);

int event_priority_init (int npri);
int event_priority_set (struct event *ev, int pri);

struct event_base *event_base_new (void);
const char *event_base_get_method (const struct event_base *);
int event_base_set (struct event_base *base, struct event *ev);
int event_base_loop (struct event_base *base, int);
int event_base_loopexit (struct event_base *base, struct timeval *tv);
int event_base_dispatch (struct event_base *base);
int event_base_once (struct event_base *base, int fd, short events, void (*cb)(int, short, void *), void *arg, struct timeval *tv);
int event_base_priority_init (struct event_base *base, int fd);





}
# 48 "event.c" 2
# 59 "event.c"
struct event_base
{
  int dummy;
};

static struct event_base *ev_x_cur;

static ev_tstamp
ev_tv_get (struct timeval *tv)
{
  if (tv)
    {
      ev_tstamp after = tv->tv_sec + tv->tv_usec * 1e-6;
      return after ? after : 1e-6;
    }
  else
    return -1.;
}




const char *
event_get_version (void)
{

  return "4" "." "24";
}

const char *
event_get_method (void)
{
  return "libev";
}

void *event_init (void)
{

  if (ev_x_cur)
    ev_x_cur = (struct event_base *)ev_loop_new (EVFLAG_AUTO);
  else
    ev_x_cur = (struct event_base *)ev_default_loop (EVFLAG_AUTO);






  return ev_x_cur;
}

const char *
event_base_get_method (const struct event_base *base)
{
  return "libev";
}

struct event_base *
event_base_new (void)
{

  return (struct event_base *)ev_loop_new (EVFLAG_AUTO);




}

void event_base_free (struct event_base *base)
{
  struct ev_loop *loop = (struct ev_loop *)base;


  if (!ev_is_default_loop (loop))
    ev_loop_destroy (loop);

}

int event_dispatch (void)
{
  return event_base_dispatch (ev_x_cur);
}
# 149 "event.c"
int event_loop (int flags)
{
  return event_base_loop (ev_x_cur, flags);
}

int event_loopexit (struct timeval *tv)
{
  return event_base_loopexit (ev_x_cur, tv);
}

event_callback_fn event_get_callback
(const struct event *ev)
{
  return ev->ev_callback;
}

static void
ev_x_cb (struct event *ev, int revents)
{
  revents &= EV_READ | EV_WRITE | EV_TIMER | EV_SIGNAL;

  ev->ev_res = revents;
  ev->ev_callback (ev->ev_fd, (short)revents, ev->ev_arg);
}

static void
ev_x_cb_sig (struct ev_loop *loop, struct ev_signal *w, int revents)
{
  struct event *ev = (struct event *)(((char *)w) - 
# 177 "event.c" 3 4
                                                   __builtin_offsetof (
# 177 "event.c"
                                                   struct event
# 177 "event.c" 3 4
                                                   , 
# 177 "event.c"
                                                   iosig.sig
# 177 "event.c" 3 4
                                                   )
# 177 "event.c"
                                                                                     );

  if (revents & EV_ERROR)
    event_del (ev);

  ev_x_cb (ev, revents);
}

static void
ev_x_cb_io (struct ev_loop *loop, struct ev_io *w, int revents)
{
  struct event *ev = (struct event *)(((char *)w) - 
# 188 "event.c" 3 4
                                                   __builtin_offsetof (
# 188 "event.c"
                                                   struct event
# 188 "event.c" 3 4
                                                   , 
# 188 "event.c"
                                                   iosig.io
# 188 "event.c" 3 4
                                                   )
# 188 "event.c"
                                                                                    );

  if ((revents & EV_ERROR) || !(ev->ev_events & 0x10))
    event_del (ev);

  ev_x_cb (ev, revents);
}

static void
ev_x_cb_to (struct ev_loop *loop, struct ev_timer *w, int revents)
{
  struct event *ev = (struct event *)(((char *)w) - 
# 199 "event.c" 3 4
                                                   __builtin_offsetof (
# 199 "event.c"
                                                   struct event
# 199 "event.c" 3 4
                                                   , 
# 199 "event.c"
                                                   to
# 199 "event.c" 3 4
                                                   )
# 199 "event.c"
                                                                              );

  event_del (ev);

  ev_x_cb (ev, revents);
}

void event_set (struct event *ev, int fd, short events, void (*cb)(int, short, void *), void *arg)
{
  if (events & EV_SIGNAL)
    do { ((ev_watcher *)(void *)(&ev->iosig.sig))->active = ((ev_watcher *)(void *)(&ev->iosig.sig))->pending = 0; ( (ev_watcher *)(void *)((&ev->iosig.sig)))->priority = (0); (((&ev->iosig.sig))->cb = (ev_x_cb_sig), memmove (&((ev_watcher *)((&ev->iosig.sig)))->cb, &((&ev->iosig.sig))->cb, sizeof (((&ev->iosig.sig))->cb))); } while (0);
  else
    do { ((ev_watcher *)(void *)(&ev->iosig.io))->active = ((ev_watcher *)(void *)(&ev->iosig.io))->pending = 0; ( (ev_watcher *)(void *)((&ev->iosig.io)))->priority = (0); (((&ev->iosig.io))->cb = (ev_x_cb_io), memmove (&((ev_watcher *)((&ev->iosig.io)))->cb, &((&ev->iosig.io))->cb, sizeof (((&ev->iosig.io))->cb))); } while (0);

  do { ((ev_watcher *)(void *)(&ev->to))->active = ((ev_watcher *)(void *)(&ev->to))->pending = 0; ( (ev_watcher *)(void *)((&ev->to)))->priority = (0); (((&ev->to))->cb = (ev_x_cb_to), memmove (&((ev_watcher *)((&ev->to)))->cb, &((&ev->to))->cb, sizeof (((&ev->to))->cb))); } while (0);

  ev->ev_base = ev_x_cur;
  ev->ev_fd = fd;
  ev->ev_events = events;
  ev->ev_pri = 0;
  ev->ev_callback = cb;
  ev->ev_arg = arg;
  ev->ev_res = 0;
  ev->ev_flags = 0x80;
}

int event_once (int fd, short events, void (*cb)(int, short, void *), void *arg, struct timeval *tv)
{
  return event_base_once (ev_x_cur, fd, events, cb, arg, tv);
}

int event_add (struct event *ev, struct timeval *tv)
{
  struct ev_loop *loop = (struct ev_loop *)ev->ev_base;

  if (ev->ev_events & EV_SIGNAL)
    {
      if (!(0 + ((ev_watcher *)(void *)(&ev->iosig.sig))->active))
        {
          do { (&ev->iosig.sig)->signum = (ev->ev_fd); } while (0);
          ev_signal_start (loop, &ev->iosig.sig);

          ev->ev_flags |= 0x04;
        }
    }
  else if (ev->ev_events & (EV_READ | EV_WRITE))
    {
      if (!(0 + ((ev_watcher *)(void *)(&ev->iosig.io))->active))
        {
          do { (&ev->iosig.io)->fd = (ev->ev_fd); (&ev->iosig.io)->events = (ev->ev_events & (EV_READ | EV_WRITE)) | EV__IOFDSET; } while (0);
          ev_io_start (loop, &ev->iosig.io);

          ev->ev_flags |= 0x02;
        }
    }

  if (tv)
    {
      ev->to.repeat = ev_tv_get (tv);
      ev_timer_again (loop, &ev->to);
      ev->ev_flags |= 0x01;
    }
  else
    {
      ev_timer_stop (loop, &ev->to);
      ev->ev_flags &= ~0x01;
    }

  ev->ev_flags |= 0x08;

  return 0;
}

int event_del (struct event *ev)
{
  struct ev_loop *loop = (struct ev_loop *)ev->ev_base;

  if (ev->ev_events & EV_SIGNAL)
    ev_signal_stop (loop, &ev->iosig.sig);
  else if (ev->ev_events & (EV_READ | EV_WRITE))
    ev_io_stop (loop, &ev->iosig.io);

  if ((0 + ((ev_watcher *)(void *)(&ev->to))->active))
    ev_timer_stop (loop, &ev->to);

  ev->ev_flags = 0x80;

  return 0;
}

void event_active (struct event *ev, int res, short ncalls)
{
  struct ev_loop *loop = (struct ev_loop *)ev->ev_base;

  if (res & EV_TIMER)
    ev_feed_event (loop, &ev->to, res & EV_TIMER);

  if (res & EV_SIGNAL)
    ev_feed_event (loop, &ev->iosig.sig, res & EV_SIGNAL);

  if (res & (EV_READ | EV_WRITE))
    ev_feed_event (loop, &ev->iosig.io, res & (EV_READ | EV_WRITE));
}

int event_pending (struct event *ev, short events, struct timeval *tv)
{
  short revents = 0;
  struct ev_loop *loop = (struct ev_loop *)ev->ev_base;

  if (ev->ev_events & EV_SIGNAL)
    {

      if ((0 + ((ev_watcher *)(void *)(&ev->iosig.sig))->active) || (0 + ((ev_watcher *)(void *)(&ev->iosig.sig))->pending))
        revents |= EV_SIGNAL;
    }
  else if (ev->ev_events & (EV_READ | EV_WRITE))
    {

      if ((0 + ((ev_watcher *)(void *)(&ev->iosig.io))->active) || (0 + ((ev_watcher *)(void *)(&ev->iosig.io))->pending))
        revents |= ev->ev_events & (EV_READ | EV_WRITE);
    }

  if (ev->ev_events & EV_TIMER || (0 + ((ev_watcher *)(void *)(&ev->to))->active) || (0 + ((ev_watcher *)(void *)(&ev->to))->pending))
    {
      revents |= EV_TIMER;

      if (tv)
        {
          ev_tstamp at = ev_now (loop);

          tv->tv_sec = (long)at;
          tv->tv_usec = (long)((at - (ev_tstamp)tv->tv_sec) * 1e6);
        }
    }

  return events & revents;
}

int event_priority_init (int npri)
{
  return event_base_priority_init (ev_x_cur, npri);
}

int event_priority_set (struct event *ev, int pri)
{
  ev->ev_pri = pri;

  return 0;
}

int event_base_set (struct event_base *base, struct event *ev)
{
  ev->ev_base = base;

  return 0;
}

int event_base_loop (struct event_base *base, int flags)
{
  struct ev_loop *loop = (struct ev_loop *)base;

  return !ev_run (loop, flags);
}

int event_base_dispatch (struct event_base *base)
{
  return event_base_loop (base, 0);
}

static void
ev_x_loopexit_cb (int revents, void *base)
{
  struct ev_loop *loop = (struct ev_loop *)base;

  ev_break (loop, EVBREAK_ONE);
}

int event_base_loopexit (struct event_base *base, struct timeval *tv)
{
  ev_tstamp after = ev_tv_get (tv);
  struct ev_loop *loop = (struct ev_loop *)base;

  ev_once (loop, -1, 0, after >= 0. ? after : 0., ev_x_loopexit_cb, (void *)base);

  return 0;
}

struct ev_x_once
{
  int fd;
  void (*cb)(int, short, void *);
  void *arg;
};

static void
ev_x_once_cb (int revents, void *arg)
{
  struct ev_x_once *once = (struct ev_x_once *)arg;

  once->cb (once->fd, (short)revents, once->arg);
  free (once);
}

int event_base_once (struct event_base *base, int fd, short events, void (*cb)(int, short, void *), void *arg, struct timeval *tv)
{
  struct ev_x_once *once = (struct ev_x_once *)malloc (sizeof (struct ev_x_once));
  struct ev_loop *loop = (struct ev_loop *)base;

  if (!once)
    return -1;

  once->fd = fd;
  once->cb = cb;
  once->arg = arg;

  ev_once (loop, fd, events & (EV_READ | EV_WRITE), ev_tv_get (tv), ev_x_once_cb, (void *)once);

  return 0;
}

int event_base_priority_init (struct event_base *base, int npri)
{


  return 0;
}
