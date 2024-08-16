#include <locale.h>
#include <stdio.h>


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	//definição de variaveis
	//os cont de periodo foram definicos como 1 para evitar erros de divisão
	int contM=1, contT=1, contN=1, contE=0, contH=0, contB=0, qntFamilia=0, age=0, qntMenor=0, qntUm=0, qntDois=0, qntTres=0, qntQuatro=0, qntCinco=0, qntSeis=0, qntMaior=0;
	char turno=NULL, area=NULL;
	double aux=0, renda=0, rendaM=0, rendaT=0, rendaN=0;
	
	
	do{
		//pequeno menu para adicionar alunos indefinidamente
		printf("========================\n\n0 - Adicionar aluno\n");
		printf("\n1 - Sair\n\n========================\n\n");
		scanf("%lf", &aux);

		if(aux == 1){
			break;
		}
		

		// verifica se foi pedido para adicionar aluno
		if(aux == 0){
			
			// cadastra as informaçoes do aluno
			printf("\n\nTurno: \n");
			scanf("\n%c", &turno);
			
			printf("\nRenda: \n");
			scanf("\n%lf", &renda);
			
			printf("\nArea do curso: \n");
			scanf("\n%c", &area);
			
			printf("\nQuantidade de familiares: \n");
			scanf("\n%d", &qntFamilia);
			
			printf("\nIdade: \n");
			scanf("\n%d", &age);
			
			//analisa a qual turno o aluno pertence e soma sua renda à renda do turno alem de almentar o contador de alunos do turno
			if( turno == 'M' ){
				rendaM= rendaM + renda;
				contM++;
			}
			if(turno == 'T'){
				rendaT= rendaT + renda;
				contT++;
			}
			if(turno == 'N'){
				rendaN= rendaN + renda;
				contN++;
			}
			// verifica se a idade do aluno esta entre 18 e 22, se a quantidade de familiares é 3 ou 4 e se a renda é superior a 1800
			if(age>=18 && age<=22 ){
				printf("\nPassou do primeiro if\n");
				if(renda>1800 ){
					printf("\nPassou do segundo if\n");
					if(qntFamilia==3 || qntFamilia==4){
						printf("\nPassou do terceiro if\n");
						//analisa a qual area o aluno pertence e almenta o contador da area de acordo
						if(area == 'E'){
							contE++;
						}
						if(area == 'H'){
							contH++;
						}
						if(area == 'B'){
							contB++;
						}
					}
				}
			}
			
			//analisa e separa os entrevistados por tamanho de famila
			if(qntFamilia == 1){
				qntUm++;
			}
			if(qntFamilia == 2){
				qntDois++;
			}
			if(qntFamilia == 3){
				qntTres++;
			}
			if(qntFamilia == 4){
				qntQuatro++;
			}
			if(qntFamilia == 5){
				qntCinco++;
			}
			if(qntFamilia == 6){
				qntSeis++;
			}
			if(qntFamilia > 6){
				qntMaior++;
			}
			if(qntFamilia < 1){
				qntMenor++;
			}
		}
		
	}while(aux != 1);
	
	
	printf("\na) \n");
	
	//os cont previamente foram startados em "1" para não ocorrer erros nas divisõa porem caso aja renda o cont é  nescessariamente superior a "1" e portanto
	// podemos subtrair o "1" o qual foi-lhe atribuido para evitar erros
	// no caso dos Cont de area não utiliza-se divisões com os mesmos ent foram definicos com 0
	if(rendaM != 0){
		contM--;
	}
	if(rendaT != 0){
		contT--;
	}
	if(rendaN != 0){
		contN--;
	}
	
	
	//verifica se ha rendas medias iguais
	if((rendaM/contM)==(rendaT/contT)){
		printf("\nA renda media da manhã e da tarde são iguais \n");
	}
	if((rendaM/contM)==(rendaN/contN)){
		printf("\nA renda media da manhã e da noite são iguais \n");
	}
	if((rendaN/contN)==(rendaT/contT)){
		printf("\nA renda media da noite e da tarde são iguais \n");
	}
	
	// verifica qual turno tem a maior renda media
	if(((rendaM/contM)>(rendaT/contT)) && ((rendaM/contM)>(rendaN/contN))){
		printf("\nO turno da manhã possui a maior renda media\n");
	}else{
		if(((rendaT/contT)>(rendaM/contM)) && ((rendaT/contT)>(rendaN/contN))){
			printf("\nO turno da Tarde possui a maior renda media\n");
		}else{
			if(((rendaN/contN)>(rendaT/contT)) && ((rendaN/contN)>(rendaM/contM))){
				printf("\nO turno da noite possui a maior renda media\n");
			}	
		}
	}
	
	// verifica qual turno tem a menor renda media
	if(((rendaM/contM)<(rendaT/contT)) && ((rendaM/contM)<(rendaN/contN))){
		printf("\nO turno da manhã possui a menor renda media\n");
	}else{
		if(((rendaT/contT)<(rendaM/contM)) && ((rendaT/contT)<(rendaN/contN))){
			printf("\nO turno da Tarde possui a menor renda media\n");
		}else{
			if(((rendaN/contN)<(rendaT/contT)) && ((rendaN/contN)<(rendaM/contM))){
				printf("\nO turno da noite possui a menor renda media\n");
			}	
		}
	}
	
	printf("\nb) \n");
	//conferindo se algum dos alunos cadastrados comprem o criterio
	if((contE+contH+contB)>0){
		// mostrando a quantia de alunos que comprem o criterio por area e quanto essa area representa em porcentagem da quantia de alunos que cumprem
		aux = ((contE*(100))/(contE+contH+contB));
		printf("\nExatas: %d que representa %4lf %%\n",contE , aux);
		aux = (contH*100)/(contE+contH+contB);
		printf("\nHumanas: %d que representa %4lf %%\n",contH , aux);
		aux = (contB*100)/(contE+contH+contB);
		printf("\nBiologicas: %d que representa %4lf %%\n",contB , aux);
		
	}else{
		// para caso ninguem cumpri o criterio informar o usuario
		printf("sem alunos com idade entre 18 e 21, renda maior que 1800 e com numero de familiares de 3 ou 4 cadastrados");
	}
	
	
	printf("\nc) \n");
	//exibir quantos alunos possuem quantos familiares ate um limite de 6
	printf("\nSem familiares: %d\n", qntMenor);
	printf("\nCom UM familiar: %d\n",qntUm);
	printf("\nCom DOIS familiares: %d\n",qntDois);
	printf("\nCom TRES familiares: %d\n",qntTres);
	printf("\nCom QUATRO familiares: %d\n",qntQuatro);
	printf("\nCom CINCO familiares: %d\n",qntCinco);
	printf("\nCom SEIS familiares: %d\n",qntSeis);
	printf("\nCom Mais de SEIS familiares: %d\n",qntMaior);
	
	return 0;
}
