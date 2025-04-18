/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isrkik <isrkik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:31:32 by isrkik            #+#    #+#             */
/*   Updated: 2025/02/23 17:38:50 by isrkik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

//check new if failed

int main()
{
    Zombie zombie("Zombie");
    zombie.announce();

    Zombie  *zombiePointer;
    zombiePointer = newZombie("ZombiePointer");
    zombiePointer->announce();
    delete(zombiePointer);

    randomChump("zombieRandom");
    return (0);
}