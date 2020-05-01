#include "ft_minilibsdl.h"

static const char *error_messages[__ERR_CODE_NUMBER] = {
	NULL, // because error_messages[SDL_ERROR] shouldn't exist.
	"Missing window intializer variable.\n",
};

void	strcat_w_endl(char *stackstr, const char *txt, const char *endl_char)
{
	strcpy(stackstr + strlen(stackstr), txt);
	strcpy(stackstr + strlen(stackstr), endl_char);
}	// can't tell if this is retarded or not yet

void	error_handler(const char *err_source, const char *err_function, int err_code)
{
	static char err_str[256];

	strcat_w_endl(err_str, err_source, " -> ");
	strcat_w_endl(err_str, err_function, " : ");
	if (err_code == SDL_ERROR)
		strcat_w_endl(err_str, SDL_GetError(), "\n\0");
	else
		strcat_w_endl(err_str, error_messages[err_code], "\n\0");
	printf("%s\n", err_str); // to be replaced with ft_putstr(err_str);
}
