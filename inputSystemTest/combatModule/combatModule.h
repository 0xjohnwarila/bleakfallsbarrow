#ifndef COMBATMODULE_H
#define COMBATMODULE_H

int combatInitPrompt(std::string enemyNameInput, std::string enemyWeaponInput, int enemyHealthInput, int enemyLevelInput);
int combatFightModule();
int damageRoller(int damageRoll);
int bossFightEndlessTerror();
void combatRunModule();
void combatUserAttackBasic();
void combatUserWait();
void combatEnemyAttack();
void combatUserSpellBasic();
void combatEnemyWait();
void givePlayerHealth();
void printOptions();
void itemChoice();
void skipPlayerTurn();
std::string randomEnemyName();
std::string randomEnemyWeapon();
std::string checkEnemyNameInput(std::string enemyNameInput);
std::string checkEnemyWeaponInput(std::string enemyWeaponInput);
std::string randomBodyPart();
std::string combatEnemyChoice();

#endif