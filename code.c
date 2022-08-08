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
	int tut=0,tut1, mem[10], mem2[10], mem3[10];
	int yok[100], u=0;
	int c=0;
	int gir1=0, gir2=0, gir3=0;
	int say=0;
	int bing=0;
	int playerguess=0, computerguess=0, trueplayerguess=0, truecomputerguess=0;
	//seviye belirleme işlemi
	int seviye;
	
	
	printf("Hangi seviyede oynamak istediğinizi giriniz: \n (kolay icin:1 orta icin:2 zor icin:3)");
	scanf("%d", &seviye);
	
	while((seviye != 1)&& (seviye != 2)&& (seviye != 3)){     //bu 3 sayıdan başka sayı girilmemesi için
		printf("hata, gecerli bir sayi giriniz");
		scanf("%d", &seviye);
	}
	
	
	if (seviye==1){
	y=16;    //kart sayısı
	n=4;     //matrisin sütun ve sayı sayısı
	m=2;     //bilgisayarın hatırlayacağı kartları kaydetmek için
	}
	else {
		if(seviye==2){
			y=36;
			n=6;
			m=5;
		}
		else {
			if(seviye==3){
				y=64;
				n=8;
				m=7;
			}
		}
	}
	
	//seviye belirleme işlemi
	
	while(say != m){             //diziyi temizlenmiş oldu
		
		mem[say]=0;
		say++;
		
	}
	
	say=0;
	
	while(say != y){             //dizi temizlenmiş oldu
		
		yok[say]=0;
		say++;
	}
	
	say=0;
	
	// tahtayı oluşturma

	srand(time(0));
	
	for(i=0;i<y;i++){                 //başta A dizisine tahtayı oluştururken kullanıcağım sayıları tek tek yazdırdım her sayıdan sadece ikişer tane 
		
		if(i >= y/2){
			x++;
			A[i]=x;
		}
		else{
			z++;
			A[i]=z;
				
		}
	}
	
	for(i=0;i<n+1;i++){                     //A dizisindeki sayıları teker teker rastgele bir şekilde Board dizisine aktarma işlemi
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
					y--;      //her sayı aktarıldığında A dizisini küçülttüm ki tekrar aynı sayılar çekilmesin

				}
			}
			
			printf("\t%d", Board[i][k]);
			if(k == n){
				printf("\n\n");  //matris görünümü için
			}
			
			
				
		}
	}
	
	// tahtayı oluşturma
	// kapalı hali
	 
	printf("\ndevam etmek icin herhangi bir sayi girin\n");
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
	while(u <= x-1){        //maksimum tajtadaki kart sayısının yarısı kadar eşleşme olabilir
		
		//oyuncu
		

		
		
		while((Board[num1][num2] == Board[num3][num4])&&(u != x)){
			if(c != 0){    //seçilen kartların tahtadan çıkarılması için
				
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
				
				trueplayerguess++;	
			}
			
			c++;
			
			if(u != x ){
				printf("sira oyuncuda, 2 kart koordinati giriniz\n\n");	
				printf("1.kartin koordinatlarini giriniz.\n\n");
			
				scanf("%d", &num1);
				scanf("%d", &num2);
			
			
				while((gir1!=1)|| (gir2!=1)){  //herhangi bir kart değişikliğinde bütün kontrollerin tekrar yapılabilmesi için
					
					while(gir2 != 1){
					
						gir2 = 1;
						while(((num1 >= n+1)|| (num2 >= n+1))||((num1 == 0)||(num2 == 0))){
						
							printf("Hata,koordinatlara uygun bir sayi saciniz\n\n");
							scanf("%d", &num1);
							scanf("%d", &num2);
							
							gir1 = gir1 + 2;
						}
						
					}
				
					while(gir1 != 1){
						
						gir1 = 1;
						
						while(say != u){
							
							while(yok[say] == Board[num1][num2]){
								
								printf("Hata, onceden eslesmis kart sectiniz. \n1.kartin kordinatlarini tekrar giriniz.\n\n");
								scanf("%d", &num1);
								scanf("%d", &num2);
									
								gir2 = gir2 + 2;
								
							}
							say++;
						}
						
						say=0;
						
					}	
				}
				
				gir1=0;
				gir2=0;
				gir3=0;
				
					
						
					                           //önceki kartları hatırlayıp kullanmak için
				if(tut<=m){
					mem[tut]=Board[num1][num2];
					mem2[tut]=num1;
					mem3[tut]=num2;
					
					tut++;
				}
				else{
					tut=0;
					mem[tut]=Board[num1][num2];
					mem2[tut]=num1;
					mem3[tut]=num2;
					
					tut++;
						
				}
			                              //önceki kartları hatırlayıp kullanmak için
			                              
			                              
				printf("\n1.kartiniz: %d\n\n", Board[num1][num2]);
				printf("2.kartin koordinatlarini giriniz.\n\n");
				
				scanf("%d", &num3);
				scanf("%d", &num4);
				
				while(((gir1!=1)|| (gir2!=1))|| (gir3!=1)){
					
					
					while(gir3 != 1){
	
						gir3 = 1;
						
						while(((num3 >= n+1)|| (num4 >= n+1))||((num3 == 0)||(num4 == 0))){
							
							printf("Hata,koordinatlara uygun bir sayi saciniz\n\n");
							scanf("%d", &num3);
							scanf("%d", &num4);
							
							gir1 = gir1 + 2;
						
						}
					
					}
					
					while(gir1 != 1){
						
						gir1 = 1;
		
						while((num1 == num3)&& (num2 == num4)){
						
							printf("Hata, ayni kordinatli iki kart secemezsiniz \n2.kartin kordinatlarini tekrar giriniz.\n\n");
							scanf("%d", &num3);
							scanf("%d", &num4);
						
							gir2 = gir2 + 2;
						
						}
					}	
					
					while(gir2 != 1){
			
						gir2 = 1;
						
						while(say != u){
							
							while(yok[say] == Board[num3][num4]){
							
								printf("Hata, onceden eslesmis kart sectiniz. \n2.kartin kordinatlarini tekrar giriniz.\n\n");
								scanf("%d", &num3);
								scanf("%d", &num4);
						
								gir3 = gir3 + 2;
						
						
							}
					
							say++;
						}
							
						say=0;
						
					}
				
				}
				
				
				gir1=0;
				gir2=0;
				gir3=0;
					
				
						
					                           //önceki kartları hatırlayıp kullanmamak için
				if(tut<=m){
					mem[tut]=Board[num3][num4];
					mem2[tut]=num3;
					mem3[tut]=num4;
					
					tut++;
				}
				else{
					tut=0;
					mem[tut]=Board[num3][num4];
					mem2[tut]=num3;
					mem3[tut]=num4;
					
					tut++;
						
				}
			                              //önceki kartları hatırlayıp kullanmak için
				printf("\n2.kartiniz: %d\n", Board[num3][num4]);
				
				playerguess++;
				
				
			}
			
			
			
		

		}
		
		
		
		//oyuncu
		
		
		//bilgisayar
		

		num1=0;
		num2=0;
		num3=0;
		num4=0;
		c=0;

		
		while((Board[num1][num2] == Board[num3][num4])&&(u != x)){
			
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
				
				truecomputerguess++;	
			}
			
			c++;
			
			if(u != x){
				
				num1 = rand() % n+1;
				num2 = rand() % n+1;
			
			
				while((gir1 != 1)&&( u != x )){
						
					gir1 = 1;
						
					while(say != u){
							
						while(yok[say] == Board[num1][num2]){
							
							num1 = rand() % n+1;
							num2 = rand() % n+1;
									
							gir1 = gir1 + 2;
								
						}
						say++;
					}
					
					say=0;
					
				}	
					
				
				gir1=0;
				gir2=0;
			
	
				printf("\nSira bilgisayarda:\n");                               
				printf("\nBilgisayarin sectigi 1.kart: %d\n num1: %d num2: %d\n\n", Board[num1][num2], num1, num2);
				
			
				while(say != m){
				
				
					
					if(mem[say]==Board[num1][num2]){
					
						tut1=say;
					
						if((mem2[tut1] != num1)&& (mem3[tut1] != num2)){
					
							printf("bing");
							bing=1;
						}
					
					}
				

				
					say++;
				}
			
				say=0;
			
								
				                           //önceki kartları hatırlayıp kullanmamak için
				if(tut<=m){
					mem[tut]=Board[num1][num2];
					mem2[tut]=num1;
					mem3[tut]=num2;
					
					tut++;
				}
				else{
					tut=0;
					mem[tut]=Board[num1][num2];
					mem2[tut]=num1;
					mem2[tut]=num2;
					
					tut++;
							
				}
			                               //önceki kartları hatırlayıp kullanmak için
				                               
					
				if(bing != 1){
					
					
					num3 = rand() % n+1;
					num4 = rand() % n+1;
				
				
					while((gir1!=1)|| (gir2!=1)){
					
					
						while(gir1 != 1){
						
							gir1 = 1;
		
							while((num1 == num3)&& (num2 == num4)){
							
								num3 = rand() % n+1;
								num4 = rand() % n+1;
							
								gir2 = gir2 + 2;
							
							}
						}
					
						while(gir2 != 1){
		
							gir2 = 1;
					
							while(say != u){
									
								while(yok[say] == Board[num3][num4]){
								
									num3 = rand() % n+1;
									num4 = rand() % n+1;
							
									gir1 = gir1 + 2;
								
							
								}
							
								say++;
							}
						
							say=0;
						
						}
					
					}
				
				
		    
		    
			
					gir1=0;
					gir2=0;
					gir3=0;
					
				
					
				                           //önceki kartları hatırlayıp kullanmamak için
					if(tut<=m){
						mem[tut]=Board[num3][num4];
						mem2[tut]=num3;
						mem3[tut]=num4;
						
						tut++;
					}
					else{
						tut=0;
						mem[tut]=Board[num3][num4];
						mem2[tut]=num3;
						mem3[tut]=num4;
						
						tut++;
							
					}
					                               //önceki kartları hatırlayıp kullanmak için
			    	                           
			       	                        
					printf("\nBilgisayarin sectigi 2.kart: %d\n num3: %d num4: %d\n\n", Board[num3][num4], num3, num4);
		
				}
			
				else{
				
					num3=mem2[tut1];
					num4=mem3[tut1];
				
					printf("\nBilgisayarin sectigi 2.kart: %d\n num3: %d num4: %d\n\n", Board[num3][num4], num3, num4);
				
				}
			
				computerguess++;
				
				
			}
				
			
			
		}
		
	num1=0;
	num2=0;
	num3=0;
	num4=0;
	c=0;	

		
	}
	
	if(trueplayerguess > truecomputerguess){
		
		printf("\noyuncu kazandi\n\nTahmin sayisi:%d", playerguess);
	}
	else{
		
		printf("\nBilgisayar kazandi\n\nTahmin sayisi:%d", computerguess);
	}
	
	
	
	return 0;
	
}