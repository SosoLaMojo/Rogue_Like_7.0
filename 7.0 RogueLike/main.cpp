#include<iostream>
#include "player.h"
#include "ennemy.h"
#include "map.h"
#include "potion.h"
#include "trap.h"
#include "GlobalRessources.h"
#include <Windows.h>
#include <time.h>


/* EXERCICE 7.0 ROGUE LIKE
Cr�er un jeu dans le style roguelike.
Vous devez afficher une map dans la console, vous pouvez choisir le taille, et ce que vous mettez dedans,
mais il faut que celle-ci soit rafra�chie au moins � chaque d�placement du personnage.
N�oubliez pas de nettoyer la console avant d�afficher quelque chose.
Pour le personnage principale il faut qu�il puisse effectuer des actions (command-based style).
Il doit �tre capable de se d�placer et de prendre des objets. Il doit �tre pr�senter par un symbole pr�cis.
Le joueur doit �tre capable de r�cup�rer des potions de vie s�il est sur la m�me case(via une action) et
s�il marche sur un pi�ge il faut que celui-ci perde de la vie. Il faut donc aussi afficher sa vie.
En plus du projet il faut rendre un document en format pdf avec un sch�ma qui explique comment les jeux s'ex�cute et
comment les classes sont li�es entre elles.
Une fois les �l�ments de bases termin� (map, personnage, d�placement, UI) vous �tes libre de faire ce que vous voulez.
N�oubliez pas de faire quelque chose de fun et amusez-vous en le faisant.
*/

int main() {

	
	
	Player player = Player(100, '@');
	Ennemy ennemy = Ennemy(100, '&');
	Potion potion = Potion(20, '$');
	Trap trap = Trap(30, '*');
	Map map = Map(player.xPlayerPosition, player.yPlayerPosition);
	srand(time(NULL));
	
	//map.Add(Ressource::player, player.xPlayerPosition, player.yPlayerPosition);
	bool isRunning = true;
	while (isRunning == true)
	{
		map.isObstacle = false;
		map.isEnnemy = false;
		map.isPotion = false;
		map.isTrap = false;
		
		system("cls");
		map.CheckWinOrDeath(player.health_, isRunning);
		map.Print();
		map.ShowMenu(player.health_);
		player.AskUserInput();
		player.CheckMove(player.UserInputs);
		map.MoveSecurity(player.xNewPlayerPosition, player.yNewPlayerPosition);
		map.UpdateMap(player.GetPlayerXposition(), player.GetPlayerYposition());
		player.MovePosition(player.xNewPlayerPosition, player.yNewPlayerPosition, map.isObstacle, map.isEnnemy, map.isPotion, map.isTrap, potion.potionVie, ennemy.attack_, trap.attackTrap, player.UserChoice);
		map.Add(Ressource::player, player.xPlayerPosition, player.yPlayerPosition);
		
	}
	

	system("pause");
	return EXIT_SUCCESS;
}