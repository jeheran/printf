#include "ft_printf.h"

int g_debug = 0;

#define F "\t%-30s: "
#define YN(b) ((b) ? "\e[92myes\e[0m" : "\e[96mno\e[0m")



void    ft_printf_conv_handler(t_settings *settings, t_flags *flags, char conv)
{
    int     i;
    int     total_len;
    char    *str;
    char    car;

    i = -1;
    total_len = 0;
    if (conv == 's')
    {
        str = va_arg(settings->parameters, char*);
        if (str == NULL)
            str = "(null)";
        if (flags->precision_on == 1)
            str = ft_substr(str, 0, flags->precision);
        
        if ((total_len = flags->width - (int)ft_strlen(str)) > 0 && flags->padding_left_minus_sign == 0)//TODO fonction ft_putchar char avec param minus
        {
            while (total_len > 0)
            {
                ft_putchar_fd(flags->pading_character, FD);
                settings->written++;
                total_len--;
            }
        }
        while (str[++i])
        {
            ft_putchar_fd(str[i], FD);
            settings->written++;
        }
        if ((total_len = flags->width - (int)ft_strlen(str)) > 0 && flags->padding_left_minus_sign == 1)//TODO code repetition
        {
            while (total_len > 0)
            {
                ft_putchar_fd(flags->pading_character, FD);
                settings->written++;
                total_len--;
            }
        }

        if (flags->precision_on == 1)
            free(str);
    }
    else if (conv == 'c')
    {
        car = va_arg(settings->parameters, char);
        total_len = 1;
        if (flags->width_on == 1 && flags->width > 1)
            total_len = flags->width;
        settings->written += total_len;
        if (flags->padding_left_minus_sign == 0)
        {
            while (total_len > 1)
            {
                ft_putchar_fd(flags->pading_character, FD);
                total_len--;
            }
        }
        ft_putchar_fd(car, FD);
        if (flags->padding_left_minus_sign == 1)
        {
            while (total_len > 1)
            {
                ft_putchar_fd(flags->pading_character, FD);
                total_len--;
            }
        }
    }
    else if (conv == 'p')
    {
        void *ptr = va_arg(settings->parameters, void*);
        
        if (flags->width_on && flags->pading_character == '0' && flags->padding_left_minus_sign == 0)
        {
            flags->precision = ft_max(flags->width - 2, flags->precision);
            flags->width_on = 0;
            flags->precision_on = 1;
            flags->width = 0;
        }
        int *len;
        len = 0;
        if (!(ptr == NULL && flags->precision == 0 && flags->precision_on == 1))
            ft_nbr_len_base(ptr, "0123456789abcdef", &len);

        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0)
        {
            //printf("~~~~~~~~~~");
            //printf("LEN :%d", len);

            //fflush(stdout);

            if (flags->precision_neg)
            {
                //fflush(stdout);
                //printf("#########");
                while (++i < (flags->width - (int)len - 2) + (flags->precision_on && flags->width_on && flags->precision != 0)) //- flags->precision))
                {
                    //fflush(stdout);
                    
                    ft_putchar_fd(flags->pading_character, FD);
                    //fflush(stdout);
                    //printf("#########");
                    
                    settings->written += 1;
                }
            }
            else
            {
                while (++i < (flags->width - 2 - ft_max(flags->precision, len))) //+ (flags->precision_on && flags->width_on && flags->precision != 0))
                {
                    //fflush(stdout);
                    
                    ft_putchar_fd(flags->pading_character, FD);
                    //fflush(stdout);
                    //printf("#########");
                    
                    settings->written += 1;
                }
            }

        }
        i = -1;
        ft_putstr_fd("0x", FD);
        settings->written += 2;
        if (flags->precision_on == 1 && flags->precision)
        {
            while (++i < (flags->precision - (int)len))
            {
                ft_putchar_fd('0', FD);
                settings->written += 1;
            }
        }
        if (len != 0)
            ft_putadress_base_fd((unsigned long)ptr, "0123456789abcdef", FD);
        settings->written += (int)len;
        i = -1;
        if (flags->padding_left_minus_sign == 1)
        {
            while (++i < (flags->width - 2 - ft_max(flags->precision, (int)len)))
            {
                ft_putchar_fd(' ', FD);
                settings->written += 1;
            }
        }
    }

    if (g_debug)
    {
        printf("\n{\n");
        printf(F"'%d'\t\t\n", "written", settings->written);
        printf(F"%s\t\t\n", "padding_left_minus_sign", YN(flags->padding_left_minus_sign));
        printf(F"%d\t\t\n", "width", flags->width);
        printf(F"%s\t\t\n", "width_on", YN(flags->width_on));
        printf(F"%d\t\t\n", "precision", flags->precision);
        printf(F"%s\t\t\n", "precision_on", YN(flags->precision_on));
        printf(F"%s\t\t\n", "precision_neg", YN(flags->precision_neg));
        printf(F"'%c'\t\t\n", "padding_char", flags->pading_character);
        printf("}\n");
    }
}