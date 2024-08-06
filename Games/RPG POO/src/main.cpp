#include <iostream>
#include "./entity/chars/Hero.hpp"
#include "./entity/chars/Princess.hpp"
#include "./entity/AbstractCharacter.hpp"
#include "./entity/mobs/Monster.hpp"
#include "./entity/AbstractMobs.hpp"
#include "./item/itens/Hammer.hpp"
#include "./item/itens/Sword.hpp"

int main()
{
    int op;
    int action;
    AbstractCharacter * player;
    AbstractMobs * monster;
    AbstractUsableItens* weapon;
    monster = new Monster();
    std::cout << "selecione seu char:" << std::endl << "1 Hero \t 2 Princess" << std::endl;
    std::cin >> op;

    if (1 == op)
    {
        player = new Hero();
    }else if(2 == op)
    {
        player = new Princess();
    }else
    {
        player = new Hero();
    }

    std::cout << "select sua arma:" << std::endl << "1 espada \t 2 martelo" << std::endl;
    std::cin >> op;
    if(op == 1)
    {
        weapon = new Sword();
    }else if (op == 2)
    {
        weapon = new Hammer();
    }else
    {
        weapon = new Sword();
    }
    player->setItem(weapon);

    while(player != NULL && monster != NULL)
    {
        //player
        std::cout << "1 atacar \t 2 usar item" << std::endl;
        std::cin >> action;
        if (1 == action)
        {
            player->atackEnemy((AbstractLivingEntity*) monster);
        }else if (2 == action)
        {
            player->useItem();
        }
        
        //monster
        monster->atackEnemy(player);

        //print result

        std::cout << "Dados:: player:" << player->getLife() << " monster: " << monster->getLife() << std::endl;

        //verify
        if (0 >= player->getLife())
        {
            delete player;
            player = NULL;
        }else 
        {
            player->passBout();
        }

        if (0 >= monster->getLife())
        {
            delete monster;
            monster = NULL;
        }else 
        {
            monster->passBout();
        }        
    }
    std::cout << "fim da batalha" << std::endl;
    if (NULL != player)
    {
        std::cout << "Parabens vc venceu de um monstro peba" << std::endl;
    } else
    {
        std::cout << "Parabens vc perdeu para monstro peba" << std::endl;
    }
    
    return 0;
}