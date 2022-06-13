/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elaachac <elaachac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:39:46 by elaachac          #+#    #+#             */
/*   Updated: 2022/06/13 13:51:31 by elaachac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONFIG_HPP
# define	CONFIG_HPP

# define PORT					6667
# define MAX_CLIENTS			30
# define TRUE					1
# define FALSE					0
# define MAX_CHANNELS			30

# define MOTD_FILE				"motd"

# define NICKNAME_VALID_CHAR 	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_[]{}\\`|"
# define CHANNEL_PREFIX			"&#+!" // channel name can only begin with one of those characters
# define DATE					"02.06.2022"
# define VERSION				"1.0"
# define USERSMODES				"io"
# define CHANNELSMODES			"kobilv"

#endif