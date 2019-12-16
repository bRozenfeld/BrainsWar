# BrainsWar

## Prérequis (système sur lequel tout fonctionne parfaitement pour nous)
* QT >= 5.10
* Windows 10 64 bits
* MinGW >= 7.3.0 32-bits 


## Architecture du projet
* src/ fichiers sources .h et .cpp
* bin/ fichiers compilé .o
* deployment/ contient l'exécutable, le répertoire images/ ainsi que les dll nécessaire pour lancer le jeu

## Instructions de compilation
* Lancer  QT.
* Accueil -> Open Project 
* Sélectionner le fichier src/brainsWar.pro
* Sélectionner Compiler -> Compiler le projet "brainsWar" ou Ctrl + B
* Copié le fichier bin/debug/brainsWar.exe dans deployment/
* Copié le dossier bin/images/ dans deployment/
* Se rendre dans votre répertoire d'installation Qt/5.13.0/MinGW 7.3.0(32-bit)
* Lancer la console Qt 5.13.0 (MinGW 7.3.0 32-bit)
* Se rendre de nouveau dans le répertoire deployment/
* Lancer la commande : windeployqt.exe brainsWar.exe -> cela va ajouter les dll nécessaires pour lancer le jeu

## Instructions d'exécution
* Double clique sur deployment/brainsWar.exe

