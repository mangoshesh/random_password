#include <iostream>
#include <limits>
#include <cstdlib>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

void copyClipboard(){
    
}

int mdpGenerator(){

// ----------------------------------------------

// init les variables

    int number;
    std::string reload;

// -----------------------------------------------

// ----------------------------------------------------

    std::cout << "Entrez un nombre de caractères pour le mod de passe : ";

    // gerer les cas d'erreurs; reinit les flags, ignorer les mauvais caracteres
    while(!(std::cin >> number) || number <= 0){

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrée invalide. Veuillez entrer un nombre entier positif : ";
        }

    // vide le buffer d'entrée pour ne pas catch le \n
   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// ----------------------------------------------------------------------------------------

// ----------------------------------------------------------------------------------------

   // initialiser un tableau avec les valeurs
   const char Caracteres[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*";

   // enlever le %0
    
   const int caractereFinal = sizeof(Caracteres) -1;
    std::cout << "" << std::endl;
   std::cout << "*****************************************" << std::endl << std::endl;


   // boucle pour rdm mdp
   std::cout << "Votre mot de passe est : " << std::endl;
   std::cout << "\033[32m" << std::endl << std::endl; // sequence ansi

   for(int i = 0; i < number; i++){
    std::cout << Caracteres[rand() % caractereFinal];
   }

   std::cout << "\033[0m" << std::endl << std::endl << std::endl; // sequences ansi
   std::cout << "*****************************************" << std::endl << std::endl;

    // std::cout << std::endl << std::endl;

// ----------------------------------------------------------------------------------------
    copyClipboard();
// ----------------------------------------------------------------------------------------

    // recommencer le programme
    
    std::cout << "Appuyez sur entrée pour recommencer ou q pour quitter : ";


    std::getline(std::cin, reload);
    if(reload.empty()){
        mdpGenerator();
    }

// ----------------------------------------------------------------------------------------

    return 0;
}


int main(int argc, char *argv[]){

    mdpGenerator();

    return 0;
}