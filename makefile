all:derle bagla calistir
derle:
	gcc -c -I "./include" ./src/StrategyA.c -o ./lib/StrategyA.o
	gcc -c -I "./include" ./src/StrategyB.c -o ./lib/StrategyB.o
	gcc -c -I "./include" ./src/ProductionA.c -o ./lib/ProductionA.o
	gcc -c -I "./include" ./src/ProductionB.c -o ./lib/ProductionB.o
	gcc -c -I "./include" ./src/Colony.c  -o ./lib/Colony.o
	gcc -c -I "./include" ./src/Game.c    -o ./lib/Game.o
	gcc -c -I "./include" ./src/Strategy.c  -o ./lib/Strategy.o
	gcc -c -I "./include" ./src/Test.c    -o ./lib/Test.o
	gcc -c -I "./include" ./src/Production.c  -o ./lib/Production.o
	gcc -c -I "./include" ./src/RandomSymbol.c  -o ./lib/RandomSymbol.o
	
	
bagla:
	gcc ./lib/StrategyA.o ./lib/StrategyB.o ./lib/ProductionA.o ./lib/ProductionB.o ./lib/Colony.o ./lib/Game.o ./lib/Strategy.o ./lib/Test.o ./lib/Production.o ./lib/RandomSymbol.o -o ./bin/program
calistir:
	./bin/program.exe