/*
 * Copyright (c) 1988, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)limits.h	8.3 (Berkeley) 1/4/94
 * $FreeBSD$
 */

#ifndef _MACHINE_LIMITS_H_
#define	_MACHINE_LIMITS_H_

#define	CHAR_BIT	8		/* number of bits in a char */
#define	MB_LEN_MAX	6		/* Allow 31 bit UTF2 */

/*
 * According to ANSI (section 2.2.4.2), the values below must be usable by
 * #if preprocessing directives.  Additionally, the expression must have the
 * same type as would an expression that is an object of the corresponding
 * type converted according to the integral promotions.  The subtraction for
 * INT_MIN, etc., is so the value is not unsigned; e.g., 0x80000000 is an
 * unsigned int for 32-bit two's complement ANSI compilers (section 3.1.3.2).
 * These numbers are for the default configuration of gcc.  They work for
 * some other compilers as well, but this should not be depended on.
 */
#define	SCHAR_MAX	0x7f		/* max value for a signed char */
#define	SCHAR_MIN	(-0x7f - 1)	/* min value for a signed char */

#define	UCHAR_MAX	0xff		/* max value for an unsigned char */

#ifdef __CHAR_UNSIGNED__
#define	CHAR_MAX	UCHAR_MAX	/* max value for a char */
#define	CHAR_MIN	0		/* min value for a char */
#else
#define	CHAR_MAX	SCHAR_MAX	/* max value for a char */
#define	CHAR_MIN	SCHAR_MIN	/* min value for a char */
#endif

#define	USHRT_MAX	0xffff		/* max value for an unsigned short */
#define	SHRT_MAX	0x7fff		/* max value for a short */
#define	SHRT_MIN	(-0x7fff - 1)	/* min value for a short */

#define	UINT_MAX	0xffffffffU	/* max value for an unsigned int */
#define	INT_MAX		0x7fffffff	/* max value for an int */
#define	INT_MIN		(-0x7fffffff - 1)	/* min value for an int */

/* Bad hack for gcc configured to give 64-bit longs. */
#ifdef _LARGE_LONG
#define	ULONG_MAX	0xffffffffffffffffUL
#define	LONG_MAX	0x7fffffffffffffffL
#define	LONG_MIN	(-0x7fffffffffffffffL - 1)
#else
#define	ULONG_MAX	0xffffffffUL	/* max value for an unsigned long */
#define	LONG_MAX	0x7fffffffL	/* max value for a long */
#define	LONG_MIN	(-0x7fffffffL - 1)	/* min value for a long */
#endif

			/* max value for an unsigned long long */
#define	ULLONG_MAX	0xffffffffffffffffULL
#define	LLONG_MAX	0x7fffffffffffffffLL	/* max value for a long long */
#define	LLONG_MIN	(-0x7fffffffffffffffLL - 1)  /* min for a long long */

#if !defined(_ANSI_SOURCE)
#define	SSIZE_MAX	INT_MAX		/* max value for a ssize_t */

#if !defined(_POSIX_SOURCE)
#define	SIZE_T_MAX	UINT_MAX	/* max value for a size_t */

#define	OFF_MAX		LLONG_MAX	/* max value for a off_t */
#define	OFF_MIN		LLONG_MIN	/* min value for a off_t */

/* Quads and long longs are the same size.  Ensure they stay in sync. */
#define	UQUAD_MAX	ULLONG_MAX	/* max value for a uquad_t */
#define	QUAD_MAX	LLONG_MAX	/* max value for a quad_t */
#define	QUAD_MIN	LLONG_MIN	/* min value for a quad_t */

#if !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS)
/*
 * ISO/IEC 9899:1999
 * 7.18.2.1 Limits of exact-width integer types
 */
/* Minimum values of exact-width signed integer types. */
#define	INT8_MIN	(-0x7f-1)
#define	INT16_MIN	(-0x7fff-1)
#define	INT32_MIN	(-0x7fffffff-1)
#define	INT64_MIN	(-0x7fffffffffffffffLL-1)

/* Maximum values of exact-width signed integer types. */
#define	INT8_MAX	0x7f
#define	INT16_MAX	0x7fff
#define	INT32_MAX	0x7fffffff
#define	INT64_MAX	0x7fffffffffffffffLL

/* Maximum values of exact-width unsigned integer types. */
#define	UINT8_MAX	0xff
#define	UINT16_MAX	0xffff
#define	UINT32_MAX	0xffffffffU
#define	UINT64_MAX	0xffffffffffffffffULL

/*
 * ISO/IEC 9899:1999
 * 7.18.2.2  Limits of minimum-width integer types
 */
/* Minimum values of minimum-width signed integer types. */
#define	INT_LEAST8_MIN	SCHAR_MIN
#define	INT_LEAST16_MIN	SHRT_MIN
#define	INT_LEAST32_MIN	INT_MIN
#define	INT_LEAST64_MIN	LLONG_MIN

/* Maximum values of minimum-width signed integer types. */
#define	INT_LEAST8_MAX	SCHAR_MAX
#define	INT_LEAST16_MAX	SHRT_MAX
#define	INT_LEAST32_MAX	INT_MAX
#define	INT_LEAST64_MAX	LLONG_MAX

/* Maximum values of minimum-width unsigned integer types. */
#define	UINT_LEAST8_MAX	 UCHAR_MAX
#define	UINT_LEAST16_MAX USHRT_MAX
#define	UINT_LEAST32_MAX UINT_MAX
#define	UINT_LEAST64_MAX ULLONG_MAX

/*
 * ISO/IEC 9899:1999
 * 7.18.2.3  Limits of fastest minimum-width integer types
 */
/* Minimum values of fastest minimum-width signed integer types. */
#define	INT_FAST8_MIN	INT_MIN
#define	INT_FAST16_MIN	INT_MIN
#define	INT_FAST32_MIN	INT_MIN
#define	INT_FAST64_MIN	LLONG_MIN

/* Maximum values of fastest minimum-width signed integer types. */
#define	INT_FAST8_MAX	INT_MAX
#define	INT_FAST16_MAX	INT_MAX
#define	INT_FAST32_MAX	INT_MAX
#define	INT_FAST64_MAX	LLONG_MAX

/* Maximum values of fastest minimum-width unsigned integer types. */
#define	UINT_FAST8_MAX	UINT_MAX
#define	UINT_FAST16_MAX	UINT_MAX
#define	UINT_FAST32_MAX	UINT_MAX
#define	UINT_FAST64_MAX	ULLONG_MAX

/*
 * ISO/IEC 9899:1999
 * 7.18.2.4  Limits of integer types capable of holding object pointers
 */
#define	INTPTR_MIN	INT_MIN
#define	INTPTR_MAX	INT_MAX
#define	UINTPTR_MAX	UINT_MAX

/*
 * ISO/IEC 9899:1999
 * 7.18.2.5  Limits of greatest-width integer types
 */
#define	INTMAX_MIN	LLONG_MIN
#define	INTMAX_MAX	LLONG_MAX
#define	UINTMAX_MAX	ULLONG_MAX

/*
 * ISO/IEC 9899:1999
 * 7.18.3  Limits of other integer types
 */
/* Limits of ptrdiff_t. */
#define	PTRDIFF_MIN	INT_MIN	
#define	PTRDIFF_MAX	INT_MAX

/* Limits of sig_atomic_t. */
#define	SIG_ATOMIC_MIN	INT_MIN
#define	SIG_ATOMIC_MAX	INT_MAX

/* Limit of size_t. */
#define	SIZE_MAX	UINT_MAX

#ifndef WCHAR_MIN /* Also possibly defined in <wchar.h> */
/* Limits of wchar_t. */
#define	WCHAR_MIN	INT_MIN
#define	WCHAR_MAX	INT_MAX

/* Limits of wint_t. */
#define	WINT_MIN	INT_MIN
#define	WINT_MAX	INT_MAX
#endif
#endif /* !defined(__cplusplus) || defined(__STDC_LIMIT_MACROS) */
#endif /* !_POSIX_SOURCE */
#endif /* !_ANSI_SOURCE */

#endif /* !_MACHINE_LIMITS_H_ */
