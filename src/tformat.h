// tformat.h

#include<string>

namespace TERM // Named constants for Linux terminal formatting sequences
{
	const std::string 
		// Font types
		BOLD_ON		=	"\e[1m",
		BOLD_OFF	=	"\e[21m",
		DIM_ON		=	"\e[2m",
		DIM_OFF		=	"\e[22m",
		ULN_ON		=	"\e[4m",	// Underline
		ULN_OFF		=	"\e[24m",
		BLINK_ON	=	"\e[5m",
		BLINK_OFF	=	"\e[25m",
		INV_ON		=	"\e[7m",	// Reverse background and foreground color
		INV_OFF		=	"\e[27m",
		HIDE_ON		=	"\e[8m",	// Hidden text
		HIDE_OFF	=	"\e[28m",
		RES			=	"\e[0m",	// Reset all above options
		// Foreground colors
		FG_DEF		=	"\e[39m",
		FG_BLACK 	=	"\e[30m",
		FG_RED		=	"\e[31m",
		FG_GREEN	=	"\e[32m",
		FG_YELLOW	=	"\e[33m",
		FG_BLUE		=	"\e[34m",
		FG_MAGENTA	=	"\e[35m",
		FG_CYAN		=	"\e[36m",
		FG_LGRAY	=	"\e[37m",
		FG_DGRAY	=	"\e[90m",
		FG_LRED		=	"\e[91m",
		FG_LGREEN	=	"\e[92m",
		FG_LYELLOW	=	"\e[93m",
		FG_LBLUE	=	"\e[94m",
		FG_LMAGENTA	=	"\e[95m",
		FG_LCYAN	=	"\e[96m",
		FG_WHITE	=	"\e[97m",
		// Background colors
		BG_DEF		=	"\e[49m",
		BG_BLACK 	=	"\e[40m",
		BG_RED		=	"\e[41m",
		BG_GREEN	=	"\e[42m",
		BG_YELLOW	=	"\e[43m",
		BG_BLUE		=	"\e[44m",
		BG_MAGENTA	=	"\e[45m",
		BG_CYAN		=	"\e[46m",
		BG_LGRAY	=	"\e[47m",
		BG_DGRAY	=	"\e[100m",
		BG_LRED		=	"\e[101m",
		BG_LGREEN	=	"\e[102m",
		BG_LYELLOW	=	"\e[103m",
		BG_LBLUE	=	"\e[104m",
		BG_LMAGENTA	=	"\e[105m",
		BG_LCYAN	=	"\e[106m",
		BG_WHITE	=	"\e[107m";
}
