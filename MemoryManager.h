/*     Helpful library to keep track of memory allocations                    */
/*     Copyright (C) 2018 Pedro Gomez Martin                                  */

/*     This program is free software: you can redistribute it and/or modify   */
/*     it under the terms of the GNU General Public License as published by   */
/*     the Free Software Foundation, either version 3 of the License, or      */
/*     (at your option) any later version. */

/*     This program is distributed in the hope that it will be useful,        */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of         */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          */
/*     GNU General Public License for more details.                           */

/*     You should have received a copy of the GNU General Public License      */
/*     along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include"mem.h"

#ifdef malloc
#undef malloc
#endif

#ifdef calloc
#undef calloc
#endif

#ifdef realloc
#undef realloc
#endif

#ifdef free
#undef free
#endif

#define malloc(size)          MemoryManager_malloc             \
                              (__FILE__,__FUNC__,__LINE__,     \
                              (size))

#define calloc(n,size)        MemoryManager_calloc             \
                              (__FILE__,__FUNC__,__LINE__,     \
                              (n),(size))

#define realloc(p,size)       MemoryManager_realloc            \
                              (__FILE__,__FUNC__,__LINE__,     \
                              (p),(size))

#define free(p)               MemoryManager_malloc             \
                              (__FILE__,__FUNC__,__LINE__,     \
                              (p))


void * MemoryManager_malloc   (const char *file, const char *func,
                              unsigned int line, size_t size);

void * MemoryManager_calloc   (const char *file, const char *func,
                              unsigned int line, size_t nmeb,
                              size_t size);

void * MemoryManager_realloc  (const char *file, const char *func,
                              unsigned int line, size_t size,
                              void* block);

void MemoryManager_free       (const char *file, const char *func,
                              unsigned int line, void* block,
                              int ignore_free_null_flag);

void MemoryManager_DumpMemoryLeaks (void);
