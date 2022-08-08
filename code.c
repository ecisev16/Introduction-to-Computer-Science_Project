#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	int A[100],Board[10][10], i, k;
	char Kapali[10][10];
	int yer;
	int x=0, z=0;
	int y, n, m;
	int devam;
	int num1=0, num2=0, num3=0, num4=0;
	int h=1, l=0;
	int gerisayim=0;
	int tut=0, mem[10];
	int yok[100], u=0;
	int c=0;
	//seviye belirleme işlemi
	int seviye;
	
	
	printf("Hangi seviyede oynamak istediğinizi giriniz: \n (kolay icin:1 orta icin:2 zor icin:3)");
	scanf("%d", &seviye);
	
	while((seviye != 1)&& (seviye != 2)&& (seviye != 3)){
		printf("hata, gecerli bir sayi giriniz.");
		scanf("%d", &seviye);
	}
	
	
	if (seviye==1){
	y=16;
	n=4;
	m=2;
	}
	else {
		if(seviye==2){
			y=36;
			n=6;
			m=4;
		}
		else {
			if(seviye==3){
				y=64;
				n=8;
				m=6;
			}
		}
	}
	
	//seviye belirleme işlemi
	
	// tahtayı oluşturma

	srand(time(0));
	
	for(i=0;i<y;i++){
		
		if(i >= y/2){
			x++;
			A[i]=x;
		}
		else{
			z++;
			A[i]=z;
				
		}
	}
	
	for(i=0;i<n+1;i++){
		for(k=0;k<n+1;k++){
			
			if((i==0)&&(k!=0)){
				Board[i][k]=h;
				h++;
			}
			else{
				
				if(k==0){
					Board[i][k]=l;
					l++;
				}
				else{
				
			
					yer = rand() % y;
					Board[i][k] = A[yer];
			
					while(yer != y){
						A[yer]=A[yer+1];
						yer++;
						
				
					}
					y--;

				}
			}
			
			printf("\t%d", Board[i][k]);
			if(k == n){
				printf("\n\n");
			}
			
			
				
		}
	}
	
	// tahtayı oluşturma
	// kapalı hali
	 
	printf("\ndevam etmek icin herhangi bir tusa basin\n");
	scanf("%d", &devam);
	
	 
	for(i=0;i<n;i++){
		for(k=0;k<n;k++){
		
			Kapali[i][k]='*';
			
			printf("\t%c", Kapali[i][k]);
			if(k == n-1){
				printf("\n\n");
			}
		}
	}
	
	// kapalı hali
	
	
	
	
	
	//oyuna geçtik
	
	
	
	
	
	while(u != x){
		
		// oyuncu
		
		while((Board[num1][num2] == Board[num3][num4])){
			
			if(c != 0){
				
				Kapali[num1-1][num2-1] = '-';
				Kapali[num3-1][num4-1] = '-';
			
				yok[u]=Board[num1][num2];
				u++;
			
				for(i=0;i<n;i++){
					for(k=0;k<n;k++){
			
						printf("\t%c", Kapali[i][k]);
						if(k == n-1){
							printf("\n\n");
						}
					}
				}	
			}
			
			printf("sira oyuncuda, 2 kart koordinati giriniz\n\n");
			printf("1.kartin koordinatlarini giriniz.\n\n");
			scanf("%d", &num1);
			scanf("%d", &num2);
			while(((num1 >= n+1)|| (num2 >= n+1))||((num1 == 0)||(num2 == 0))){         //sadece tahtadaki kordinatlar girildiği sürece devam etmesi için
				
				printf("hata, lutfen gecerli bir koordinat giriniz. \n\n");
				
				scanf("%d", &num1);
				scanf("%d", &num2);
				
			}
			
				                           //önceki kartları hatırlayıp kullanmamak için
			if(tut!=m){
				mem[tut]=Board[num1][num2];
				tut++;
			}
			else{
				tut=0;
				mem[tut]=Board[num1][num2];
				tut++;
					
			}
			                               //önceki kartları hatırlayıp kullanmak için
			                               
			                               
			printf("1. Sectiginiz kart: %d\n\n", Board[num1][num2]);
			printf("2.kartin koordinatlarini giriniz. \n\n");
	
	
			scanf("%d", &num3);
			scanf("%d", &num4);
			
			while(((num3 >= n+1)|| (num4 >= n+1))||((num3 == 0)||(num4 == 0))){      
				
				printf("hata, lutfen gecerli bir kart koordinatı giriniz. \n\n");
				
				scanf("%d", &num3);
				scanf("%d", &num4);
				
			
			
			
				// aynı kartı iki defa seçme durumu
			
			
			
				while((num1 == num3)&& (num2 == num4)){
			
					tut--;                         // önceki tutulan sayıları silsin diye
				
					printf("hata, ayni karti 2 defa secemezsiniz\n\n");
					printf("lutfen 2. kartın koordinatlarini tekrar giriniz\n\n");
					scanf("%d", &num3);
					scanf("%d", &num4);
				
	    		}
			
			
			// aynı kartı iki defa seçme durumu
			
		    } 
				
			if(tut != m){
				mem[tut]=Board[num3][num4];
				tut++;
			}
			else{
				tut=0;
				mem[tut]=Board[num3][num4];
				tut++;
				
			}
			printf("2. Sectiginiz kart: %d\n\n", Board[num3][num4]);
			
			if(Board[num1][num2] == Board[num3][num4]){
				
				c++;
				
			}
				
		}
			
	
		// oyuncu bitti
		
		
		// bilgisayar
		
		
		
		printf("sira bilgisayarda\n");
		
		num1 = rand() % n;
		num2 = rand() % n;
		
		
		if(tut != m){
				mem[tut]=Board[num3][num4];
				tut++;
		}
		else{
			tut=0;
			mem[tut]=Board[num1][num2];
			tut++;
				
		}
		
		
		printf("1. sectigi kart: %d\n", Board[num1][num2]);
		
		num3 = rand() % n;
		num4 = rand() % n;
		
		if(tut != m){
				mem[tut]=Board[num3][num4];
				tut++;
		}
		else{
			tut=0;
			mem[tut]=Board[num1][num2];
			tut++;
				
		}
		
		
		printf("2. sectigi kart: %d\n", Board[num3][num4]);
		
		while(Board[num1][num2] == Board[num3][num4]){
			
			gerisayim=gerisayim+2;
			
			printf("sira bilgisayarda\n");
		
			num1 = rand() % n;
			num2 = rand() % n;
			
			if(tut != m){
				mem[tut]=Board[num3][num4];
				tut++;
			}
			else{
				tut=0;
				mem[tut]=Board[num1][num2];
				tut++;
				
			}
			
			
			printf("1. sectigi kart: %d\n", Board[num1][num2]);
		
			num3 = rand() % n;
			num4 = rand() % n;
			
			if(tut != m){
				mem[tut]=Board[num3][num4];
				tut++;
			}
			else{
				tut=0;
				mem[tut]=Board[num1][num2];
				tut++;
			}
			
			
			printf("2. sectigi kart: %d\n", Board[num3][num4]);
			
		}
		
	}
	
	
		
	

	return 0;
	
}
