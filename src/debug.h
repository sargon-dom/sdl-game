#ifndef DEBUG_H
#define DEBUG_H

#ifdef DEBUG
#include <stdio.h>
#define debug(message) \
	fprintf(stderr, \
			"%s:%u # " message "\n", \
			__FILE__, __LINE__ \
			)
#else
#define debug(message) ((void)0)
#endif

#endif

