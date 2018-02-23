#ifndef COMBATMODULE_H
#define COMBATMODULE_H

int combatInitPrompt(std::string enemyNameInput, std::string enemyWeaponInput, int enemyHealthInput, int enemyLevelInput);
int combatFightModule();
void combatRunModule();
void combatUserAttackBasic();
void combatUserWait();
std::string combatEnemyChoice();
void combatEnemyAttack();
void combatUserSpellBasic();
void combatEnemyWait();
void givePlayerHealth();
void printOptions();
std::string randomEnemyName();
std::string randomEnemyWeapon();
std::string checkEnemyNameInput(std::string enemyNameInput);
std::string checkEnemyWeaponInput(std::string enemyWeaponInput);
std::string randomBodyPart();

#endif