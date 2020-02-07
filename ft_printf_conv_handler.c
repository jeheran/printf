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

    else if (conv == 'p')
    {
        void *ptr = va_arg(settings->parameters, void*);
        
        int *len;
        len = 0;
        if (!(ptr == NULL && flags->precision == 0 && flags->precision_on == 1))
            ft_nbr_len_base(ptr, "0123456789abcdef", &len);

        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0 && flags->pading_character == '0' && flags->precision_on == 0)
        {
            flags->width_on = 0;
            flags->precision_on = 1;
            flags->precision = ft_max(flags->width - 2, flags->precision);
        }
        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0)
        {
            int max = (flags->width - 2 - ft_max(flags->precision, len));
            if (flags->precision_neg)
                max = (flags->width - (int)len - 2) + (flags->precision_on && flags->width_on && flags->precision != 0);
            while (++i < max && (settings->written += 1))
                ft_putchar_fd(' ', FD);
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
    else if (conv == 'x' || conv == 'X')
        {
        unsigned int ptr = va_arg(settings->parameters, unsigned int);
        
        int *len;
        len = 0;
        if (!(ptr == NULL && flags->precision == 0 && flags->precision_on == 1))
            ft_nbr_len_base(ptr, "0123456789abcdef", &len);

        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0 && flags->pading_character == '0' && flags->precision_on == 0)
        {
            flags->width_on = 0;
            flags->precision_on = 1;
            flags->precision = ft_max(flags->width, flags->precision);
        }
        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0)
        {
            int max = (flags->width - ft_max(flags->precision, len));
            if (flags->precision_neg)
                max = (flags->width - (int)len) + (flags->precision_on && flags->width_on && flags->precision != 0);
            while (++i < max && (settings->written += 1))
                ft_putchar_fd(' ', FD);
        }
        i = -1;
        if (flags->precision_on == 1 && flags->precision)
        {
            while (++i < (flags->precision - (int)len))
            {
                ft_putchar_fd('0', FD);
                settings->written += 1;
            }
        }
        if (len != 0)
            ft_putadress_base_fd((unsigned long)ptr, conv == 'x' ? "0123456789abcdef" : "0123456789ABCDEF", FD);
        settings->written += (int)len;
        i = -1;
        if (flags->padding_left_minus_sign == 1)
        {
            while (++i < (flags->width - ft_max(flags->precision, (int)len)))
            {
                ft_putchar_fd(' ', FD);
                settings->written += 1;
            }
        }
    }
       else if (conv == 'u')
        {
        unsigned int ptr = va_arg(settings->parameters, unsigned int);
        
        int *len;
        len = 0;
        if (!(ptr == NULL && flags->precision == 0 && flags->precision_on == 1))
            ft_nbr_len_base(ptr, "0123456789", &len);

        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0 && flags->pading_character == '0' && flags->precision_on == 0)
        {
            flags->width_on = 0;
            flags->precision_on = 1;
            flags->precision = ft_max(flags->width, flags->precision);
        }
        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0)
        {
            int max = (flags->width - ft_max(flags->precision, len));
            if (flags->precision_neg)
                max = (flags->width - (int)len) + (flags->precision_on && flags->width_on && flags->precision != 0);
            while (++i < max && (settings->written += 1))
                ft_putchar_fd(' ', FD);
        }
        i = -1;
        if (flags->precision_on == 1 && flags->precision)
        {
            while (++i < (flags->precision - (int)len))
            {
                ft_putchar_fd('0', FD);
                settings->written += 1;
            }
        }
        if (len != 0)
            ft_putadress_base_fd((unsigned long)ptr, "0123456789", FD);
        settings->written += (int)len;
        i = -1;
        if (flags->padding_left_minus_sign == 1)
        {
            while (++i < (flags->width - ft_max(flags->precision, (int)len)))
            {
                ft_putchar_fd(' ', FD);
                settings->written += 1;
            }
        }
    }
else if (conv == 'd' || conv == 'i')
    {
        long nbr = 0 + va_arg(settings->parameters, int);
        
        int neg = nbr < 0;
        nbr = neg ? -nbr : nbr;

        int *len;
        len = 0;
        if (!(nbr == 0 && flags->precision == 0 && flags->precision_on == 1))
            ft_nbr_len_base(nbr, "0123456789", &len);

        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0 && flags->pading_character == '0' && flags->precision_on == 0)
        {
            flags->width_on = 0;
            flags->precision_on = 1;
            flags->precision = ft_max(flags->width - neg, flags->precision);
        }
        if (flags->width_on == 1 && flags->padding_left_minus_sign == 0)
        {
            int max = (flags->width - neg - ft_max(flags->precision, len));
            if (flags->precision_neg)
                max = (flags->width - (int)len - neg) + (flags->precision_on && flags->width_on && flags->precision != 0);
            while (++i < max && (settings->written += 1))
                ft_putchar_fd(' ', FD);
        }
        i = -1;
        if (neg)
            ft_putstr_fd("-", FD);
        settings->written += neg;
        if (flags->precision_on == 1 && flags->precision)
        {
            while (++i < (flags->precision - (int)len))
            {
                ft_putchar_fd('0', FD);
                settings->written += 1;
            }
        }
        if (len != 0)
            ft_putadress_base_fd(nbr, "0123456789", FD);
        settings->written += (int)len;
        i = -1;
        if (flags->padding_left_minus_sign == 1)
        {
            while (++i < (flags->width - neg - ft_max(flags->precision, (int)len)))
            {
                ft_putchar_fd(' ', FD);
                settings->written += 1;
            }
        }
    }
    else
    {
        if (conv == 'c')
            car = va_arg(settings->parameters, char);
        else
            car = conv;
        total_len = 1;
        //printf("x\n"); fflush(stdout);
        if (flags->width_on == 1 && flags->width > 1)
            total_len = flags->width;
        //printf("y\n"); fflush(stdout);
        settings->written += total_len;
        if (flags->padding_left_minus_sign == 0)
        {
            //printf("z\n"); fflush(stdout);
            while (total_len > 1)
            {
                ft_putchar_fd(flags->pading_character, FD);
                total_len--;
            }
        }
        //printf("a\n"); fflush(stdout);
        ft_putchar_fd(car, FD);
        //printf("b\n"); fflush(stdout);
        if (flags->padding_left_minus_sign == 1)
        {
            //printf("d\n"); fflush(stdout);
            while (total_len > 1)
            {
                ft_putchar_fd(flags->pading_character, FD);
                total_len--;
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