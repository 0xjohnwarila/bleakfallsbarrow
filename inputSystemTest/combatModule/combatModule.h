#ifndef COMBATMODULE_H
#define COMBATMODULE_H

int combatInitPrompt(std::string enemyNameInput, int enemyHealthInput, int enemyLevelInput);
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

#endif