/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppernati <ppernati@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 19:17:12 by ppernati          #+#    #+#             */
/*   Updated: 2026/05/07 14:23:17 by ppernati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <glib.h>
#include <locale.h>
#include <libft.h>

#include <ctype.h>
#include <bsd/string.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct {
  int fd;
} FdFixture;

static void fd_fixture_set_up (FdFixture *fixture, gconstpointer user_data)
{
	(void) user_data;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	fixture->fd = open("./tempfile", O_CREAT | O_TRUNC | O_RDWR, mode);
}

static void fd_fixture_tear_down (FdFixture *fixture, gconstpointer user_data)
{
	(void) user_data;
	close(fixture->fd);
}

void	libft_ft_isalpha(void)
{
	g_assert_cmpint(ft_isalpha('\0'), ==, 0);
	g_assert_cmpint(ft_isalpha('\a'), ==, 0);
	g_assert_cmpint(ft_isalpha('\b'), ==, 0);
	g_assert_cmpint(ft_isalpha('\t'), ==, 0);
	g_assert_cmpint(ft_isalpha('\n'), ==, 0);
	g_assert_cmpint(ft_isalpha('\v'), ==, 0);
	g_assert_cmpint(ft_isalpha('\f'), ==, 0);
	g_assert_cmpint(ft_isalpha('\r'), ==, 0);
	g_assert_cmpint(ft_isalpha(' '), ==, 0);
	g_assert_cmpint(ft_isalpha('!'), ==, 0);
	g_assert_cmpint(ft_isalpha('?'), ==, 0);
	g_assert_cmpint(ft_isalpha(','), ==, 0);
	g_assert_cmpint(ft_isalpha('.'), ==, 0);
	g_assert_cmpint(ft_isalpha('#'), ==, 0);
	g_assert_cmpint(ft_isalpha('$'), ==, 0);
	g_assert_cmpint(ft_isalpha('%'), ==, 0);
	g_assert_cmpint(ft_isalpha('('), ==, 0);
	g_assert_cmpint(ft_isalpha(')'), ==, 0);
	g_assert_cmpint(ft_isalpha('{'), ==, 0);
	g_assert_cmpint(ft_isalpha('}'), ==, 0);
	g_assert_cmpint(ft_isalpha('0'), ==, 0);
	g_assert_cmpint(ft_isalpha('5'), ==, 0);
	g_assert_cmpint(ft_isalpha('9'), ==, 0);
	g_assert_cmpint(ft_isalpha('a'), ==, 1);
	g_assert_cmpint(ft_isalpha('k'), ==, 1);
	g_assert_cmpint(ft_isalpha('z'), ==, 1);
	g_assert_cmpint(ft_isalpha('A'), ==, 1);
	g_assert_cmpint(ft_isalpha('K'), ==, 1);
	g_assert_cmpint(ft_isalpha('Z'), ==, 1);
	g_assert_cmpint(ft_isalpha('+'), ==, 0);
	g_assert_cmpint(ft_isalpha('-'), ==, 0);
	g_assert_cmpint(ft_isalpha('='), ==, 0);
	g_assert_cmpint(ft_isalpha('/'), ==, 0);
	g_assert_cmpint(ft_isalpha('~'), ==, 0);
	g_assert_cmpint(ft_isalpha('\x7F'), ==, 0);
	g_assert_cmpint(ft_isascii('\xFF'), ==, 0);
}

void	libft_ft_isdigit(void)
{
	g_assert_cmpint(ft_isdigit('\0'), ==, 0);
	g_assert_cmpint(ft_isdigit('\a'), ==, 0);
	g_assert_cmpint(ft_isdigit('\b'), ==, 0);
	g_assert_cmpint(ft_isdigit('\t'), ==, 0);
	g_assert_cmpint(ft_isdigit('\n'), ==, 0);
	g_assert_cmpint(ft_isdigit('\v'), ==, 0);
	g_assert_cmpint(ft_isdigit('\f'), ==, 0);
	g_assert_cmpint(ft_isdigit('\r'), ==, 0);
	g_assert_cmpint(ft_isdigit(' '), ==, 0);
	g_assert_cmpint(ft_isdigit('!'), ==, 0);
	g_assert_cmpint(ft_isdigit('?'), ==, 0);
	g_assert_cmpint(ft_isdigit(','), ==, 0);
	g_assert_cmpint(ft_isdigit('.'), ==, 0);
	g_assert_cmpint(ft_isdigit('#'), ==, 0);
	g_assert_cmpint(ft_isdigit('$'), ==, 0);
	g_assert_cmpint(ft_isdigit('%'), ==, 0);
	g_assert_cmpint(ft_isdigit('('), ==, 0);
	g_assert_cmpint(ft_isdigit(')'), ==, 0);
	g_assert_cmpint(ft_isdigit('{'), ==, 0);
	g_assert_cmpint(ft_isdigit('}'), ==, 0);
	g_assert_cmpint(ft_isdigit('0'), ==, 1);
	g_assert_cmpint(ft_isdigit('5'), ==, 1);
	g_assert_cmpint(ft_isdigit('9'), ==, 1);
	g_assert_cmpint(ft_isdigit('a'), ==, 0);
	g_assert_cmpint(ft_isdigit('k'), ==, 0);
	g_assert_cmpint(ft_isdigit('z'), ==, 0);
	g_assert_cmpint(ft_isdigit('A'), ==, 0);
	g_assert_cmpint(ft_isdigit('K'), ==, 0);
	g_assert_cmpint(ft_isdigit('Z'), ==, 0);
	g_assert_cmpint(ft_isdigit('+'), ==, 0);
	g_assert_cmpint(ft_isdigit('-'), ==, 0);
	g_assert_cmpint(ft_isdigit('='), ==, 0);
	g_assert_cmpint(ft_isdigit('/'), ==, 0);
	g_assert_cmpint(ft_isdigit('~'), ==, 0);
	g_assert_cmpint(ft_isdigit('\x7F'), ==, 0);
	g_assert_cmpint(ft_isascii('\xFF'), ==, 0);
}

void	libft_ft_isalnum(void)
{
	g_assert_cmpint(ft_isalnum('\0'), ==, 0);
	g_assert_cmpint(ft_isalnum('\a'), ==, 0);
	g_assert_cmpint(ft_isalnum('\b'), ==, 0);
	g_assert_cmpint(ft_isalnum('\t'), ==, 0);
	g_assert_cmpint(ft_isalnum('\n'), ==, 0);
	g_assert_cmpint(ft_isalnum('\v'), ==, 0);
	g_assert_cmpint(ft_isalnum('\f'), ==, 0);
	g_assert_cmpint(ft_isalnum('\r'), ==, 0);
	g_assert_cmpint(ft_isalnum(' '), ==, 0);
	g_assert_cmpint(ft_isalnum('!'), ==, 0);
	g_assert_cmpint(ft_isalnum('?'), ==, 0);
	g_assert_cmpint(ft_isalnum(','), ==, 0);
	g_assert_cmpint(ft_isalnum('.'), ==, 0);
	g_assert_cmpint(ft_isalnum('#'), ==, 0);
	g_assert_cmpint(ft_isalnum('$'), ==, 0);
	g_assert_cmpint(ft_isalnum('%'), ==, 0);
	g_assert_cmpint(ft_isalnum('('), ==, 0);
	g_assert_cmpint(ft_isalnum(')'), ==, 0);
	g_assert_cmpint(ft_isalnum('{'), ==, 0);
	g_assert_cmpint(ft_isalnum('}'), ==, 0);
	g_assert_cmpint(ft_isalnum('0'), ==, 1);
	g_assert_cmpint(ft_isalnum('5'), ==, 1);
	g_assert_cmpint(ft_isalnum('9'), ==, 1);
	g_assert_cmpint(ft_isalnum('a'), ==, 1);
	g_assert_cmpint(ft_isalnum('k'), ==, 1);
	g_assert_cmpint(ft_isalnum('z'), ==, 1);
	g_assert_cmpint(ft_isalnum('A'), ==, 1);
	g_assert_cmpint(ft_isalnum('K'), ==, 1);
	g_assert_cmpint(ft_isalnum('Z'), ==, 1);
	g_assert_cmpint(ft_isalnum('+'), ==, 0);
	g_assert_cmpint(ft_isalnum('-'), ==, 0);
	g_assert_cmpint(ft_isalnum('='), ==, 0);
	g_assert_cmpint(ft_isalnum('/'), ==, 0);
	g_assert_cmpint(ft_isalnum('~'), ==, 0);
	g_assert_cmpint(ft_isalnum('\x7F'), ==, 0);
	g_assert_cmpint(ft_isascii('\xFF'), ==, 0);
}

void	libft_ft_isascii(void)
{
	g_assert_cmpint(ft_isascii('\0'), ==, 1);
	g_assert_cmpint(ft_isascii('\a'), ==, 1);
	g_assert_cmpint(ft_isascii('\b'), ==, 1);
	g_assert_cmpint(ft_isascii('\t'), ==, 1);
	g_assert_cmpint(ft_isascii('\n'), ==, 1);
	g_assert_cmpint(ft_isascii('\v'), ==, 1);
	g_assert_cmpint(ft_isascii('\f'), ==, 1);
	g_assert_cmpint(ft_isascii('\r'), ==, 1);
	g_assert_cmpint(ft_isascii(' '), ==, 1);
	g_assert_cmpint(ft_isascii('!'), ==, 1);
	g_assert_cmpint(ft_isascii('?'), ==, 1);
	g_assert_cmpint(ft_isascii(','), ==, 1);
	g_assert_cmpint(ft_isascii('.'), ==, 1);
	g_assert_cmpint(ft_isascii('#'), ==, 1);
	g_assert_cmpint(ft_isascii('$'), ==, 1);
	g_assert_cmpint(ft_isascii('%'), ==, 1);
	g_assert_cmpint(ft_isascii('('), ==, 1);
	g_assert_cmpint(ft_isascii(')'), ==, 1);
	g_assert_cmpint(ft_isascii('{'), ==, 1);
	g_assert_cmpint(ft_isascii('}'), ==, 1);
	g_assert_cmpint(ft_isascii('0'), ==, 1);
	g_assert_cmpint(ft_isascii('5'), ==, 1);
	g_assert_cmpint(ft_isascii('9'), ==, 1);
	g_assert_cmpint(ft_isascii('a'), ==, 1);
	g_assert_cmpint(ft_isascii('k'), ==, 1);
	g_assert_cmpint(ft_isascii('z'), ==, 1);
	g_assert_cmpint(ft_isascii('A'), ==, 1);
	g_assert_cmpint(ft_isascii('K'), ==, 1);
	g_assert_cmpint(ft_isascii('Z'), ==, 1);
	g_assert_cmpint(ft_isascii('+'), ==, 1);
	g_assert_cmpint(ft_isascii('-'), ==, 1);
	g_assert_cmpint(ft_isascii('='), ==, 1);
	g_assert_cmpint(ft_isascii('/'), ==, 1);
	g_assert_cmpint(ft_isascii('~'), ==, 1);
	g_assert_cmpint(ft_isascii('\x7F'), ==, 1);
	g_assert_cmpint(ft_isascii('\xFF'), ==, 0);
}

void	libft_ft_isprint(void)
{
	g_assert_cmpint(ft_isprint('\0'), ==, 0);
	g_assert_cmpint(ft_isprint('\a'), ==, 0);
	g_assert_cmpint(ft_isprint('\b'), ==, 0);
	g_assert_cmpint(ft_isprint('\t'), ==, 0);
	g_assert_cmpint(ft_isprint('\n'), ==, 0);
	g_assert_cmpint(ft_isprint('\v'), ==, 0);
	g_assert_cmpint(ft_isprint('\f'), ==, 0);
	g_assert_cmpint(ft_isprint('\r'), ==, 0);
	g_assert_cmpint(ft_isprint(' '), ==, 1);
	g_assert_cmpint(ft_isprint('!'), ==, 1);
	g_assert_cmpint(ft_isprint('?'), ==, 1);
	g_assert_cmpint(ft_isprint(','), ==, 1);
	g_assert_cmpint(ft_isprint('.'), ==, 1);
	g_assert_cmpint(ft_isprint('#'), ==, 1);
	g_assert_cmpint(ft_isprint('$'), ==, 1);
	g_assert_cmpint(ft_isprint('%'), ==, 1);
	g_assert_cmpint(ft_isprint('('), ==, 1);
	g_assert_cmpint(ft_isprint(')'), ==, 1);
	g_assert_cmpint(ft_isprint('{'), ==, 1);
	g_assert_cmpint(ft_isprint('}'), ==, 1);
	g_assert_cmpint(ft_isprint('0'), ==, 1);
	g_assert_cmpint(ft_isprint('5'), ==, 1);
	g_assert_cmpint(ft_isprint('9'), ==, 1);
	g_assert_cmpint(ft_isprint('a'), ==, 1);
	g_assert_cmpint(ft_isprint('k'), ==, 1);
	g_assert_cmpint(ft_isprint('z'), ==, 1);
	g_assert_cmpint(ft_isprint('A'), ==, 1);
	g_assert_cmpint(ft_isprint('K'), ==, 1);
	g_assert_cmpint(ft_isprint('Z'), ==, 1);
	g_assert_cmpint(ft_isprint('+'), ==, 1);
	g_assert_cmpint(ft_isprint('-'), ==, 1);
	g_assert_cmpint(ft_isprint('='), ==, 1);
	g_assert_cmpint(ft_isprint('/'), ==, 1);
	g_assert_cmpint(ft_isprint('~'), ==, 1);
	g_assert_cmpint(ft_isprint('\x7F'), ==, 0);
	g_assert_cmpint(ft_isprint('\xFF'), ==, 0);
}

void	libft_ft_strlen(void)
{
	g_assert_cmpuint(ft_strlen(NULL), ==, 0);
	g_assert_cmpuint(ft_strlen(""), ==, 0);
	g_assert_cmpuint(ft_strlen("Hello"), ==, 5);
	g_assert_cmpuint(ft_strlen("Hello World"), ==, 11);
}

void	libft_ft_memset(void)
{
	char test[] = "0000000000";
	g_assert_null(ft_memset(NULL, 'b', 5));
	g_assert(ft_memset(test, 'b', 0) == test);
	g_assert_cmpstr(test, == ,"0000000000");
	g_assert(ft_memset(test, 'b', 1) == test);
	g_assert_cmpstr(test, == ,"b000000000");
	g_assert(ft_memset(test, 'b', 5) == test);
	g_assert_cmpstr(test, == ,"bbbbb00000");
}

void	libft_ft_bzero(void)
{
	char test[] = "0000000000";
	ft_bzero(NULL, 5);
	ft_bzero(test, 0);
	g_assert_cmpstr(test, == ,"0000000000");
    ft_bzero(test, 1);
	g_assert_cmpstr(test, == ,"\0000000000");
	ft_bzero(test, 5);
	g_assert_cmpstr(test, == ,"\0\0\0\0\000000");
}

void	libft_ft_memcpy(void)
{
	char test1[] = "0000000000";
	char test2[] = "1234567890";
	g_assert_null(ft_memcpy(NULL, test2, 5));
	g_assert(ft_memcpy(test1, NULL, 5) == test1);
	g_assert_cmpstr(test1, == ,"0000000000");
	g_assert(ft_memcpy(test1, test2, 0) == test1);
	g_assert_cmpstr(test1, == ,"0000000000");
	g_assert(ft_memcpy(test1, test2, 1) == test1);
	g_assert_cmpstr(test1, == ,"1000000000");
	g_assert(ft_memcpy(test1, test2, 5) == test1);
	g_assert_cmpstr(test1, == ,"1234500000");
}

void	libft_ft_memmove(void)
{
	char test1[] = "0000000000";
	char test2[] = "1234567890";
	g_assert_null(ft_memmove(NULL, test2, 5));
	g_assert(ft_memmove(test1, NULL, 5) == test1);
	g_assert_cmpstr(test1, == ,"0000000000");
	g_assert(ft_memmove(test1, test2, 0) == test1);
	g_assert_cmpstr(test1, == ,"0000000000");
	g_assert(ft_memmove(test1, test2, 1) == test1);
	g_assert_cmpstr(test1, == ,"1000000000");
	g_assert(ft_memmove(test1, test2, 5) == test1);
	g_assert_cmpstr(test1, == ,"1234500000");
	g_assert(ft_memmove(test2, test2, 5) == test2);
	g_assert_cmpstr(test2, == ,"1234567890");
	g_assert(ft_memmove(test2, test2 + 1, 3) == test2);
	g_assert_cmpstr(test2, == ,"2344567890");
	g_assert(ft_memmove(test2 + 5, test2 + 4, 3) == test2 + 5);
	g_assert_cmpstr(test2, == ,"2344556790");
}


void	libft_ft_strlcpy(void)
{
	char test1[] = "0000000000";
	char test2[] = "12345";

//	g_assert_cmpuint(ft_strlcpy(NULL, test2, 5), ==, strlen(test2));
//	g_assert_cmpuint(ft_strlcpy(test1, NULL, 5), ==, 0);
	g_assert_cmpstr(test1, ==, "0000000000");

	g_assert_cmpuint(ft_strlcpy(test1, test2, 0), ==, strlen(test2));
	g_assert_cmpstr(test1, ==, "0000000000");
	
	g_assert_cmpuint(ft_strlcpy(test1, test2, 3), ==, strlen(test2));
	g_assert_cmpstr(test1, ==, "12");
	g_assert_cmpuint(ft_strlcpy(test1, test2, sizeof(test1)), ==, strlen(test2));
	g_assert_cmpstr(test1, ==, "12345");
	g_assert_cmpuint(ft_strlcpy(test1, test2, 6), ==, strlen(test2));
	g_assert_cmpstr(test1, ==, "12345");
	g_assert_cmpuint(ft_strlcpy(test1, test2, 5), ==, strlen(test2));
	g_assert_cmpstr(test1, ==, "1234");
}

void	libft_ft_strlcat(void)
{
	char dest[11];
	const char *src1 = "12345";
	const char *src2 = "12";

	strcpy(dest, "0000000000");
	//g_assert_cmpuint(ft_strlcat(NULL, src1, 5), ==, strlen(src1));
	//g_assert_cmpuint(ft_strlcat(dest, NULL, 5), ==, 0);
	g_assert_cmpstr(dest, ==, "0000000000");

	g_assert_cmpuint(ft_strlcat(dest, src1, 0), ==, 0 + strlen(src1));
	g_assert_cmpstr(dest, ==, "0000000000");
	
	g_assert_cmpuint(ft_strlcat(dest, src1, 3), ==, 3 + strlen(src1));
	g_assert_cmpstr(dest, ==, "0000000000");
	g_assert_cmpuint(ft_strlcat(dest, src1, sizeof(dest)), ==, strlen(dest) + strlen(src1));
	g_assert_cmpstr(dest, ==, "0000000000");
	g_assert_cmpuint(ft_strlcat(dest, src1, 6), ==, 6 + strlen(src1));
	g_assert_cmpstr(dest, ==, "0000000000");
	g_assert_cmpuint(ft_strlcat(dest, src1, 5), ==, 5 + strlen(src1));
	g_assert_cmpstr(dest, ==, "0000000000");

	strcpy(dest, "000");
	g_assert_cmpuint(ft_strlcat(dest, src2, 0), ==, 0 + strlen(src2));
	g_assert_cmpstr(dest, ==, "000");
	
	g_assert_cmpuint(ft_strlcat(dest, src2, 3), ==, 3 + strlen(src2));
	g_assert_cmpstr(dest, ==, "000");
	g_assert_cmpuint(ft_strlcat(dest, src2, sizeof(dest)), ==, 3 + strlen(src2));
	g_assert_cmpstr(dest, ==, "00012");
	g_assert_cmpuint(ft_strlcat(dest, src2, 6), ==, 5 + strlen(src2));
	g_assert_cmpstr(dest, ==, "00012");
	g_assert_cmpuint(ft_strlcat(dest, src2, 5), ==, 5 + strlen(src2));
	g_assert_cmpstr(dest, ==, "00012");

	strcpy(dest, "0");
	g_assert_cmpuint(ft_strlcat(dest, src2, 0), ==, 0 + strlen(src2));
	g_assert_cmpstr(dest, ==, "0");
	
	g_assert_cmpuint(ft_strlcat(dest, src2, 3), ==, 1 + strlen(src2));
	g_assert_cmpstr(dest, ==, "01");
	g_assert_cmpuint(ft_strlcat(dest, src2, sizeof(dest)), ==, 2 + strlen(src2));
	g_assert_cmpstr(dest, ==, "0112");
	g_assert_cmpuint(ft_strlcat(dest, src2, 6), ==, 4 + strlen(src2));
	g_assert_cmpstr(dest, ==, "01121");
	g_assert_cmpuint(ft_strlcat(dest, src2, 5), ==, 5 + strlen(src2));
	g_assert_cmpstr(dest, ==, "01121");

	strcpy(dest, "");
	g_assert_cmpuint(ft_strlcat(dest, src2, 0), ==, 0 + strlen(src2));
	g_assert_cmpstr(dest, ==, "");
	
	g_assert_cmpuint(ft_strlcat(dest, src2, 3), ==, 0 + strlen(src2));
	g_assert_cmpstr(dest, ==, "12");
	g_assert_cmpuint(ft_strlcat(dest, src2, sizeof(dest)), ==, 2 + strlen(src2));
	g_assert_cmpstr(dest, ==, "1212");
	g_assert_cmpuint(ft_strlcat(dest, src2, 6), ==, 4 + strlen(src2));
	g_assert_cmpstr(dest, ==, "12121");
	g_assert_cmpuint(ft_strlcat(dest, src2, 5), ==, 5 + strlen(src2));
	g_assert_cmpstr(dest, ==, "12121");
}

void	libft_ft_toupper(void)
{
	g_assert_cmpint(ft_toupper('a'), ==, 'A');
	g_assert_cmpint(ft_toupper('l'), ==, 'L');
	g_assert_cmpint(ft_toupper('z'), ==, 'Z');
	g_assert_cmpint(ft_toupper('K'), ==, 'K');
	g_assert_cmpint(ft_toupper('.'), ==, '.');
	g_assert_cmpint(ft_toupper('5'), ==, '5');
	g_assert_cmpint(ft_toupper(' '), ==, ' ');
}

void	libft_ft_tolower(void)
{
	g_assert_cmpint(ft_tolower('A'), ==, 'a');
	g_assert_cmpint(ft_tolower('L'), ==, 'l');
	g_assert_cmpint(ft_tolower('Z'), ==, 'z');
	g_assert_cmpint(ft_tolower('k'), ==, 'k');
	g_assert_cmpint(ft_tolower('.'), ==, '.');
	g_assert_cmpint(ft_tolower('5'), ==, '5');
	g_assert_cmpint(ft_tolower(' '), ==, ' ');
}

void	libft_ft_strchr(void)
{
	const char *str = "Hello World";
	g_assert(ft_strchr(str, 'H') == str);
	g_assert(ft_strchr(str, 'l') == str + 2);
	g_assert(ft_strchr(str, ' ') == str + 5);
	g_assert(ft_strchr(str, 'd') == str + 10);
	g_assert(ft_strchr(str, '\0') == str + 11);
	g_assert_null(ft_strchr(str, ';'));
}

void	libft_ft_strrchr(void)
{
	const char *str = "Hello World";
	g_assert(ft_strrchr(str, 'H') == str);
	g_assert(ft_strrchr(str, 'l') == str + 9);
	g_assert(ft_strrchr(str, ' ') == str + 5);
	g_assert(ft_strrchr(str, 'd') == str + 10);
	g_assert(ft_strrchr(str, '\0') == str + 11);
	g_assert_null(ft_strchr(str, ';'));
}

void	libft_ft_strncmp(void)
{
	g_assert_cmpint(ft_strncmp("", "", 0), ==, strncmp("", "", 0));
	g_assert_cmpint(ft_strncmp("", "", 5), ==, strncmp("", "", 5));
	g_assert_cmpint(ft_strncmp("", "Hello", 5), ==, strncmp("", "Hello", 5));
	g_assert_cmpint(ft_strncmp("Hello", "", 5), ==, strncmp("Hello", "", 5));
	g_assert_cmpint(ft_strncmp("Hello", "Hellq", 5), ==, strncmp("Hello", "Hellq", 5));
	g_assert_cmpint(ft_strncmp("Hellq", "Hello", 5), ==, strncmp("Hellq", "Hello", 5));
	g_assert_cmpint(ft_strncmp("Hello", "Hell", 4), ==, strncmp("Hello", "Hell", 4));
	g_assert_cmpint(ft_strncmp("Hello", "Hell", 5), ==, strncmp("Hello", "Hell", 5));
	g_assert_cmpint(ft_strncmp("Hello", "Hello World", 5), ==, strncmp("Hello", "Hello World", 5));
	g_assert_cmpint(ft_strncmp("test\200", "test\0", 6), ==, strncmp("test\200", "test\0", 6));
}

void	libft_ft_memchr(void)
{
	const char *str = "Hello World";
	g_assert(ft_memchr(str, 'H', 11) == str);
	g_assert(ft_memchr(str, 'l', 11) == str + 2);
	g_assert(ft_memchr(str, ' ', 11) == str + 5);
	g_assert(ft_memchr(str, 'd', 11) == str + 10);
	g_assert_null(ft_memchr(str, 'd', 10));
	g_assert_null(ft_memchr(str, ';', 11));
}

void	libft_ft_memcmp(void)
{
	g_assert_cmpint(ft_memcmp("", "", 0), ==, memcmp("", "", 0));
	g_assert_cmpint(ft_memcmp("Hello", "Hellq", 5), ==, memcmp("Hello", "Hellq", 5));
	g_assert_cmpint(ft_memcmp("Hellq", "Hello", 5), ==, memcmp("Hellq", "Hello", 5));
	g_assert_cmpint(ft_memcmp("Hello", "Hello World", 5), ==, memcmp("Hello", "Hello World", 5));
}

void	libft_ft_strnstr(void)
{
	const char *big = "Hello World";
	g_assert(ft_strnstr(big, "", 5) == big);
	g_assert(ft_strnstr(big, "Hello", 5) == big);
	g_assert(ft_strnstr(big, "ll", 5) == big + 2);
	g_assert_null(ft_strnstr(big, "World", 5));
	g_assert(ft_strnstr(big, "World", 11) == big + 6);
	g_assert_null(ft_strnstr(big, "World", 8));
	g_assert(ft_strnstr(big, "Wo", 8) == big + 6);


	g_assert(strnstr(big, "", 5) == big);
	g_assert(strnstr(big, "Hello", 5) == big);
	g_assert(strnstr(big, "ll", 5) == big + 2);
	g_assert_null(strnstr(big, "World", 5));
	g_assert(strnstr(big, "World", 11) == big + 6);
	g_assert_null(strnstr(big, "World", 8));
	g_assert(strnstr(big, "Wo", 8) == big + 6);
}

void	libft_ft_atoi(void)
{
	g_assert_cmpint(ft_atoi("0"), ==, atoi("0"));
	g_assert_cmpint(ft_atoi("1"), ==, atoi("1"));
	g_assert_cmpint(ft_atoi("01"), ==, atoi("01"));
	g_assert_cmpint(ft_atoi("\t \n1"), ==, atoi("\t \n1"));
	g_assert_cmpint(ft_atoi("--1"), ==, atoi("--1"));
	g_assert_cmpint(ft_atoi("++1"), ==, atoi("++1"));
	g_assert_cmpint(ft_atoi("-+1"), ==, atoi("-+1"));
	g_assert_cmpint(ft_atoi("-+1"), ==, atoi("-+1"));
	g_assert_cmpint(ft_atoi("-1"), ==, atoi("-1"));
	g_assert_cmpint(ft_atoi("+1"), ==, atoi("+1"));
	g_assert_cmpint(ft_atoi("10"), ==, atoi("10"));
	g_assert_cmpint(ft_atoi("12345"), ==, atoi("12345"));
	g_assert_cmpint(ft_atoi("2147483647"), ==, atoi("2147483647"));
	g_assert_cmpint(ft_atoi("-2147483648"), ==, atoi("-2147483648"));
}

void	libft_ft_calloc(void)
{
	int arr[10] = {0};
	size_t arr_size = sizeof(arr);
	size_t arr_len = arr_size / sizeof(*arr);
	void *ptr;

	ptr = ft_calloc(sizeof(int), arr_len);
	g_assert_cmpmem(ptr, arr_size, arr, arr_size);
	free(ptr);
	ptr = ft_calloc(sizeof(int), 0);
	g_assert_nonnull(ptr);
	free(ptr);
	ptr = ft_calloc(0, arr_size);
	g_assert_nonnull(ptr);
	free(ptr);

	ptr = calloc(sizeof(int), arr_len);
	g_assert_cmpmem(ptr, arr_size, arr, arr_size);
	free(ptr);
	ptr = calloc(sizeof(int), 0);
	g_assert_nonnull(ptr);
	free(ptr);
	ptr = calloc(0, arr_size);
	g_assert_nonnull(ptr);
	free(ptr);
}

void	libft_ft_strdup(void)
{
	void *ptr;

	ptr = ft_strdup("");
	g_assert_cmpstr(ptr, ==, "");
	free(ptr);
	ptr = ft_strdup("Hello World");
	g_assert_cmpstr(ptr, ==, "Hello World");
	free(ptr);

	ptr = strdup("");
	g_assert_cmpstr(ptr, ==, "");
	free(ptr);
	ptr = strdup("Hello World");
	g_assert_cmpstr(ptr, ==, "Hello World");
	free(ptr);
}

void	libft_ft_substr(void)
{
	void *ptr;

	ptr = ft_substr("Hello", 0, 0);
	g_assert_cmpstr(ptr, ==, "");
	free(ptr);
	ptr = ft_substr("Hello", 10, 10);
	g_assert_cmpstr(ptr, ==, "");
	free(ptr);
	ptr = ft_substr("Hello", 0, 5);
	g_assert_cmpstr(ptr, ==, "Hello");
	free(ptr);
	ptr = ft_substr("Hello", 0, 3);
	g_assert_cmpstr(ptr, ==, "Hel");
	free(ptr);
	ptr = ft_substr("Hello", 2, 2);
	g_assert_cmpstr(ptr, ==, "ll");
	free(ptr);
	ptr = ft_substr("Hello", 2, 3);
	g_assert_cmpstr(ptr, ==, "llo");
	free(ptr);
	ptr = ft_substr("Hello", 3, 5);
	g_assert_cmpstr(ptr, ==, "lo");
	free(ptr);
	ptr = ft_substr("Hello", 4, 5);
	g_assert_cmpstr(ptr, ==, "o");
	free(ptr);
	ptr = ft_substr("Hello", 5, 5);
	g_assert_cmpstr(ptr, ==, "");
	free(ptr);
}

void	libft_ft_strjoin(void)
{
	char	*ptr;
	ptr = ft_strjoin(NULL, NULL);
	g_assert_null(ptr);
	free(ptr);
	ptr = ft_strjoin("one", NULL);
	g_assert_cmpstr(ptr, ==, "one");
	free(ptr);
	ptr = ft_strjoin(NULL, "two");
	g_assert_cmpstr(ptr, ==, "two");
	free(ptr);
	ptr = ft_strjoin("one", "");
	g_assert_cmpstr(ptr, ==, "one");
	free(ptr);
	ptr = ft_strjoin("", "two");
	g_assert_cmpstr(ptr, ==,"two");
	free(ptr);
	ptr = ft_strjoin("one", "two");
	g_assert_cmpstr(ptr, ==,"onetwo");
	free(ptr);
}

void	libft_ft_strtrim(void)
{
	char	*ptr;
	ptr = ft_strtrim(NULL, NULL);
	g_assert_null(ptr);
	free(ptr);
	ptr = ft_strtrim("one", NULL);
	g_assert_cmpstr(ptr, ==, "one");
	free(ptr);
	ptr = ft_strtrim(NULL, "two");
	g_assert_null(ptr);
	free(ptr);
	ptr = ft_strtrim("", "");
	g_assert_cmpstr(ptr, ==, "");
	free(ptr);
	ptr = ft_strtrim("", "123");
	g_assert_cmpstr(ptr, ==, "");
	free(ptr);
	ptr = ft_strtrim("one", "");
	g_assert_cmpstr(ptr, ==, "one");
	free(ptr);
	ptr = ft_strtrim("one67", "1234567890");
	g_assert_cmpstr(ptr, ==, "one");
	free(ptr);
	ptr = ft_strtrim("23one", "1234567890");
	g_assert_cmpstr(ptr, ==, "one");
	free(ptr);
	ptr = ft_strtrim("23one67", "1234567890");
	g_assert_cmpstr(ptr, ==, "one");
	free(ptr);
	ptr = ft_strtrim("one", "1234567890");
	g_assert_cmpstr(ptr, ==, "one");
	free(ptr);
	ptr = ft_strtrim("    one  \n ", " \t\n");
	g_assert_cmpstr(ptr, ==,"one");
	free(ptr);
	ptr = ft_strtrim("", "\0");
	g_assert_cmpstr(ptr, ==,"");
	free(ptr);
	ptr = ft_strtrim("\0\0\0", "\0");
	g_assert_cmpstr(ptr, ==,"");
	free(ptr);
}

void cmp_arrays(char **arr1, char **arr2)
{
	while (*arr1 || *arr2)
	{
		g_assert_cmpstr(*arr1, ==, *arr2);
		++arr1;
		++arr2;
	}
}

static void	free_str_array(char **str)
{
	char	**it;

	it = str;
	while (it && *it)
	{
		free(*it);
		++it;
	}
	free(str);
}

void libft_ft_split(void)
{
	char	**ptr;

	ptr = ft_split("one/two/three", '/');
	char *test1[] = {"one", "two", "three", NULL};
	cmp_arrays(ptr, test1);
	free_str_array(ptr);

	ptr = ft_split("/one/two/three/", '/');
	char *test2[] = {"", "one", "two", "three", "", NULL};
	cmp_arrays(ptr, test2);
	free_str_array(ptr);

	ptr = ft_split("::", ':');
	char *test3[] = {"", "", "", NULL};
	cmp_arrays(ptr, test3);
	free_str_array(ptr);

	ptr = ft_split("one", ':');
	char *test4[] = {"one", NULL};
	cmp_arrays(ptr, test4);
	free_str_array(ptr);

	ptr = ft_split(":", ':');
	char *test5[] = {"", "", NULL};
	cmp_arrays(ptr, test5);
	free_str_array(ptr);

	ptr = ft_split("", ':');
	char *test6[] = {"", NULL};
	cmp_arrays(ptr, test6);
	free_str_array(ptr);
}

void libft_ft_itoa(void)
{
	char	*ptr;

	ptr = ft_itoa(0);
	g_assert_cmpstr(ptr, ==, "0");
	free(ptr);

	ptr = ft_itoa(-1);
	g_assert_cmpstr(ptr, ==, "-1");
	free(ptr);

	ptr = ft_itoa(1);
	g_assert_cmpstr(ptr, ==, "1");
	free(ptr);

	ptr = ft_itoa(123456789);
	g_assert_cmpstr(ptr, ==, "123456789");
	free(ptr);

	ptr = ft_itoa(-123456789);
	g_assert_cmpstr(ptr, ==, "-123456789");
	free(ptr);

	ptr = ft_itoa(2147483647);
	g_assert_cmpstr(ptr, ==, "2147483647");
	free(ptr);

	ptr = ft_itoa(-2147483648);
	g_assert_cmpstr(ptr, ==, "-2147483648");
	free(ptr);
}

char ft_strmapi_helper1(unsigned int i, char c)
{
	if (i < 5)
		return '0';
	return (c);
}

char ft_strmapi_helper2(unsigned int i, char c)
{
	(void) i;
	return (ft_toupper(c));
}

char ft_strmapi_helper3(unsigned int i, char c)
{
	(void) i;
	return (ft_tolower(c));
}

void libft_ft_strmapi(void)
{
	const char	*str = "Hello World";
	char	*ptr;

	g_assert_null(ft_strmapi(NULL, ft_strmapi_helper1));
	ptr = ft_strmapi("", ft_strmapi_helper1);
	g_assert_cmpstr(ptr, ==, "");
	free(ptr);
	ptr = ft_strmapi(str, NULL);
	g_assert_cmpstr(ptr, ==, str);
	free(ptr);
	ptr = ft_strmapi(str, ft_strmapi_helper1);
	g_assert_cmpstr(ptr, ==, "00000 World");
	free(ptr);
	ptr = ft_strmapi(str, ft_strmapi_helper2);
	g_assert_cmpstr(ptr, ==, "HELLO WORLD");
	free(ptr);
	ptr = ft_strmapi(str, ft_strmapi_helper3);
	g_assert_cmpstr(ptr, ==, "hello world");
	free(ptr);
}

void ft_striteri_helper1(unsigned int i, char *c)
{
	if (i < 5)
		*c = '0';
}

void ft_striteri_helper2(unsigned int i, char *c)
{
	(void) i;
	*c = ft_toupper(*c);
}

void ft_striteri_helper3(unsigned int i, char *c)
{
	(void) i;
	*c = ft_tolower(*c);
}

void libft_ft_striteri(void)
{
	const char	*str = "Hello World";
	char		test[12];

	ft_striteri(NULL, ft_striteri_helper1);
	
	ft_strlcpy(test, "", sizeof(test));
	ft_striteri(test, ft_striteri_helper1);
	g_assert_cmpstr(test, ==, "");

	ft_strlcpy(test, str, sizeof(test));
	ft_striteri(test, NULL);
	g_assert_cmpstr(test, ==, str);

	ft_strlcpy(test, str, sizeof(test));
	ft_striteri(test, ft_striteri_helper1);
	g_assert_cmpstr(test, ==, "00000 World");

	ft_strlcpy(test, str, sizeof(test));
	ft_striteri(test, ft_striteri_helper2);
	g_assert_cmpstr(test, ==, "HELLO WORLD");

	ft_strlcpy(test, str, sizeof(test));
	ft_striteri(test, ft_striteri_helper3);
	g_assert_cmpstr(test, ==, "hello world");
}

void libft_ft_putchar_fd(FdFixture *fixture, gconstpointer user_data)
{
	char buffer[50];
	(void) user_data;

	ft_putchar_fd('a', fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "a");

	lseek(fixture->fd, 0, SEEK_SET);
	ft_putchar_fd('b', fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "b");

	lseek(fixture->fd, 0, SEEK_SET);
	ft_putchar_fd('a', fixture->fd);
	ft_putchar_fd('b', fixture->fd);
	ft_putchar_fd('c', fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "abc");
}

void libft_ft_putstr_fd(FdFixture *fixture, gconstpointer user_data)
{
	char buffer[50];
	(void) user_data;

	ft_putstr_fd("Hello World", fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "Hello World");

	lseek(fixture->fd, 0, SEEK_SET);
	ft_putstr_fd("one", fixture->fd);
	ft_putstr_fd("two", fixture->fd);
	ft_putstr_fd("three", fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "onetwothree");
}

void libft_ft_putendl_fd(FdFixture *fixture, gconstpointer user_data)
{
	char buffer[50];
	(void) user_data;

	ft_putendl_fd("Hello World", fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "Hello World\n");

	lseek(fixture->fd, 0, SEEK_SET);
	ft_putendl_fd("one", fixture->fd);
	ft_putendl_fd("two", fixture->fd);
	ft_putendl_fd("three", fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "one\ntwo\nthree\n");
}

void libft_ft_putnbr_fd(FdFixture *fixture, gconstpointer user_data)
{
	char buffer[50];
	(void) user_data;

	ft_putnbr_fd(12345, fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "12345");

	lseek(fixture->fd, 0, SEEK_SET);
	ft_putnbr_fd(1, fixture->fd);
	ft_putnbr_fd(-20, fixture->fd);
	ft_putnbr_fd(300, fixture->fd);
	lseek(fixture->fd, 0, SEEK_SET);
	buffer[read(fixture->fd, buffer, sizeof(buffer))] = '\0';
	g_assert_cmpstr(buffer, ==, "1-20300");
}

void libft_ft_lstnew(void)
{
	t_list	*list;
	const char	*str = "Hello World";

	list = ft_lstnew((void*)str);
	
	g_assert_nonnull(list);
	g_assert_cmpstr(list->content, ==, str);
	g_assert_null(list->next);
	free(list);
}

void libft_ft_lstadd_front(void)
{
	t_list	*list;
	t_list	*list_new;

	list = ft_lstnew("World");
	list_new = ft_lstnew("Hello");
	
	ft_lstadd_front(&list, list_new);
	g_assert_nonnull(list);
	g_assert_nonnull(list->next);
	g_assert_cmpstr(list->content, ==, "Hello");
	g_assert_cmpstr(list->next->content, ==, "World");

	free(list->next);
	free(list);
}

void libft_ft_lstsize(void)
{
	t_list	*list;

	list = ft_lstnew("one");
	
	g_assert_cmpuint(ft_lstsize(list), ==, 1);
	ft_lstadd_front(&list, ft_lstnew("two"));
	g_assert_cmpuint(ft_lstsize(list), ==, 2);
	ft_lstadd_front(&list, ft_lstnew("three"));
	g_assert_cmpuint(ft_lstsize(list), ==, 3);

	free(list->next->next);
	free(list->next);
	free(list);
}

void libft_ft_lstlast(void)
{
	t_list	*list;
	t_list	*last;

	list = ft_lstnew("one");
	last = ft_lstlast(list);
	g_assert_nonnull(last);
	g_assert_cmpstr(last->content, ==, "one");
	g_assert_null(last->next);
	
	ft_lstadd_front(&list, ft_lstnew("two"));
	ft_lstadd_front(&list, ft_lstnew("three"));

	last = ft_lstlast(list);
	g_assert_nonnull(last);
	g_assert_cmpstr(last->content, ==, "one");
	g_assert_null(last->next);

	free(list->next->next);
	free(list->next);
	free(list);
}

void libft_ft_lstadd_back(void)
{
	t_list	*list;
	t_list	*last;

	list = ft_lstnew("one");
	
	ft_lstadd_back(&list, ft_lstnew("two"));
	ft_lstadd_back(&list, ft_lstnew("three"));

	g_assert_nonnull(list);
	g_assert_cmpstr(list->content, ==, "one");
	g_assert_nonnull(list->next);

	last = ft_lstlast(list);
	g_assert_nonnull(last);
	g_assert_cmpstr(last->content, ==, "three");
	g_assert_null(last->next);

	free(list->next->next);
	free(list->next);
	free(list);
}

void do_nothing(void* v)
{
	(void) v;
	return ;
}

void libft_ft_lstdelone(void)
{
	t_list	*list;

	list = ft_lstnew("one");
	ft_lstdelone(list, do_nothing);
	list = ft_lstnew(ft_strdup("two"));
	ft_lstdelone(list, free);
}

void libft_ft_lstclear(void)
{
	t_list	*list;

	list = ft_lstnew("one");
	ft_lstadd_back(&list, ft_lstnew("two"));
	ft_lstadd_back(&list, ft_lstnew("three"));
	ft_lstclear(&list, do_nothing);
	g_assert_null(list);

	list = ft_lstnew(ft_strdup("one"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("two")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("three")));
	ft_lstclear(&list, free);
	g_assert_null(list);
}

void capitalize(void *ptr)
{
	char* str;

	str = ptr;
	str[0] = ft_toupper(str[0]);
}

void libft_ft_lstiter(void)
{
	t_list	*list;

	list = ft_lstnew(ft_strdup("one"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("two")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("three")));
	ft_lstiter(list, capitalize);
	g_assert_cmpstr(list->content, ==, "One");
	g_assert_cmpstr(list->next->content, ==, "Two");
	g_assert_cmpstr(list->next->next->content, ==, "Three");
	ft_lstclear(&list, free);
}

void* capitalize_dup(void *ptr)
{
	char* new_str;

	new_str = ft_strdup(ptr);
	new_str[0] = ft_toupper(new_str[0]);
	return new_str;
}

void libft_ft_lstmap(void)
{
	t_list	*list;
	t_list	*new_list;
	

	list = ft_lstnew("one");
	ft_lstadd_back(&list, ft_lstnew("two"));
	ft_lstadd_back(&list, ft_lstnew("three"));
	g_assert_null(ft_lstmap(NULL, capitalize_dup, free));
	g_assert_null(ft_lstmap(list, NULL, free));
	g_assert_null(ft_lstmap(list, capitalize_dup, NULL));
	new_list = ft_lstmap(list, capitalize_dup, free);
	g_assert_cmpstr(new_list->content, ==, "One");
	g_assert_cmpstr(new_list->next->content, ==, "Two");
	g_assert_cmpstr(new_list->next->next->content, ==, "Three");
	ft_lstclear(&list, do_nothing);
	ft_lstclear(&new_list, free);
}

int	main(int argc, char *argv[])
{
	setlocale(LC_ALL, "");
	g_test_init(&argc, &argv, NULL);
	g_test_add_func("/libft/ft_isalpha", libft_ft_isalpha);
	g_test_add_func("/libft/ft_isdigit", libft_ft_isdigit);
	g_test_add_func("/libft/ft_isalnum", libft_ft_isalnum);
	g_test_add_func("/libft/ft_isascii", libft_ft_isascii);
	g_test_add_func("/libft/ft_isprint", libft_ft_isprint);
	g_test_add_func("/libft/ft_strlen", libft_ft_strlen);
	g_test_add_func("/libft/ft_memset", libft_ft_memset);
	g_test_add_func("/libft/ft_bzero", libft_ft_bzero);
	g_test_add_func("/libft/ft_memcpy", libft_ft_memcpy);
	g_test_add_func("/libft/ft_memmove", libft_ft_memmove);
	g_test_add_func("/libft/ft_strlcpy", libft_ft_strlcpy);
	g_test_add_func("/libft/ft_strlcat", libft_ft_strlcat);
	g_test_add_func("/libft/ft_toupper", libft_ft_toupper);
	g_test_add_func("/libft/ft_tolower", libft_ft_tolower);
	g_test_add_func("/libft/ft_strchr", libft_ft_strchr);
	g_test_add_func("/libft/ft_strrchr", libft_ft_strrchr);
	g_test_add_func("/libft/ft_strncmp", libft_ft_strncmp);
	g_test_add_func("/libft/ft_memchr", libft_ft_memchr);
	g_test_add_func("/libft/ft_memcmp", libft_ft_memcmp);
	g_test_add_func("/libft/ft_strnstr", libft_ft_strnstr);
	g_test_add_func("/libft/ft_atoi", libft_ft_atoi);
	g_test_add_func("/libft/ft_calloc", libft_ft_calloc);
	g_test_add_func("/libft/ft_strdup", libft_ft_strdup);
	g_test_add_func("/libft/ft_substr", libft_ft_substr);
	g_test_add_func("/libft/ft_strjoin", libft_ft_strjoin);
	g_test_add_func("/libft/ft_strtrim", libft_ft_strtrim);
	g_test_add_func("/libft/ft_split", libft_ft_split);
	g_test_add_func("/libft/ft_itoa", libft_ft_itoa);
	g_test_add_func("/libft/ft_strmapi", libft_ft_strmapi);
	g_test_add_func("/libft/ft_striteri", libft_ft_striteri);
	g_test_add("/libft/ft_putchar_fd", FdFixture, NULL, fd_fixture_set_up, libft_ft_putchar_fd, fd_fixture_tear_down);
	g_test_add("/libft/ft_putstr_fd", FdFixture, NULL, fd_fixture_set_up, libft_ft_putstr_fd, fd_fixture_tear_down);
	g_test_add("/libft/ft_putendl_fd", FdFixture, NULL, fd_fixture_set_up, libft_ft_putendl_fd, fd_fixture_tear_down);
	g_test_add("/libft/ft_putnbr_fd", FdFixture, NULL, fd_fixture_set_up, libft_ft_putnbr_fd, fd_fixture_tear_down);
	g_test_add_func("/libft/ft_lstnew", libft_ft_lstnew);
	g_test_add_func("/libft/ft_lstadd_front", libft_ft_lstadd_front);
	g_test_add_func("/libft/ft_lstsize", libft_ft_lstsize);
	g_test_add_func("/libft/ft_lstlast", libft_ft_lstlast);
	g_test_add_func("/libft/ft_lstadd_back", libft_ft_lstadd_back);
	g_test_add_func("/libft/ft_lstdelone", libft_ft_lstdelone);
	g_test_add_func("/libft/ft_lstclear", libft_ft_lstclear);
	g_test_add_func("/libft/ft_lstiter", libft_ft_lstiter);
	g_test_add_func("/libft/ft_lstmap", libft_ft_lstmap);
	return (g_test_run());
}
