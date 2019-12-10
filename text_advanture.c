
#include<stdio.h>
#define DECISION "where you go ?\n1    village\n2    adventure\n3    personal information\n4  save(first game please save)   "//待添加 
#define DECISION2 "Quest :1.Slime Forest  2.Goblin tribe  3.Ghost castle" 
void fjshop(void);//arm shop
void wqshop(void);// wepoen shop
void vill(void);//villge
void zdmk(void);//attack
void lvup(void);//level up
void slm(void);//slime
void slm1(void);
void slm2(void);//end
void gbl(void);//goblin
void gbl1(void);
void gbl2(void);//end
void gr(void);//ghost
void gr1(void);//
void gr2(void);//end
void maoxian(void);
void vill(void);
void pi(void);//personal information
void cd(void);//save 
int hp=200,mp=20,sp,ex=0,p=5,q=20,lv=1,i=1,eak=0,edf=0,gd=0,viz=0,sh,tybosshp,x,hpboss,fb;
 
 
int main(void)
{
while(2>1)
{
	
	while(x==0)
	{
		printf("%s\n",DECISION);
		scanf("%d",&x);
		while(x==1)
		{
			vill();
			viz=0;
			x=0;
		}
		while(x==2)
		{
			maoxian();
			x=0;
		}
		while(x==3)
		{
			pi();
			x=0;
		}
		while(x==4)
		{
			cd();
			x=0;
		}
	}
}
return 0;
}
 void cd(void)
 {
 	 int du;
 	 printf("load or save?\n1  load\n2  save\n3  cancel\n");
	 scanf("%d",&du); 
	 int a[]={lv,hp,mp,ex,gd};
	 while(du==1)
  {
     FILE *fpRead=fopen("data.txt","r");
     int b[5];
	for(int i=0;i<5;i++)
	{
		fscanf(fpRead,"%d ",&b[i]);
		a[i]=b[i];
	}
	lv=a[0],hp=a[1],mp=a[2],ex=a[3],gd=a[4];
    du=-1;
  }	
	 while(du==2)
  {
	 FILE *fpWrite=fopen("data.txt","w");
	for(int i=0;i<5;i++)
	{
	fprintf(fpWrite,"%d ",a[i]);
    }
    fclose(fpWrite);
    du=-1;
  }
  	 while(du==3)
  {
    du=-1;
  }
}
void pi(void)//personal imformation 
 {
 printf("                  personal imfomation                \n") ;
 printf("title :Rokkie  \n");
 printf("level:%d    hp:%d     mp:%d     exe:%d     gold:%d    \n",lv,hp,mp,ex,gd); 
 printf("skill damage :1.strike:%d   2.bloodthirsty: (you will be strong when boss strong)   3.Star Burst Stream:%d  \n",p,q);
 }
void lvup(void)//level up 
{
	while(ex>100*lv)//differece monster difference ex 
 
{
 
printf("level up, your level: %d\n",lv+1);	
 
p=p+3;
 
q=q+10;
 
ex=ex-100*lv;
 
lv=lv+1;
 
hp=200+20*lv;
 
mp=20+2*lv;
 
 
 
}
} 
void vill(void)//village
{
	while(viz==0)
{
	printf(" Welcome , warrior\n where you want go\n1    weapon\n2    armor\n3    leave\n");
	scanf("%d",&viz);
	while(viz>=3)
	{
		printf("level now...\n");
		viz=-1;
	}
	
	
		while(viz==1)
	{	
  		wqshop();
  	}
  	    while(viz==2)
	{
		fjshop();
	}
}
}
void wqshop(void)//wepon  
{
		while(viz==1)
		{   int wq=0,dj=1,cj=1;
			printf("Hello, warrior\n what you need now \n1    Short sword (atk+10) 500 gold   \n2  longsword (atk + 30) 2000 gold\n3 exit the weapons store\n");
			scanf("%d",&wq);
			if(wq>2)
			{
				while(wq>3)
				{
					printf("not open\n");
					wq=0;
				}
				while(wq==3)
				{
					printf("quit\n;");
					viz=0;
					wq=0;
				}
			}
			else
			{
				while(wq==1)
				{
				if(gd>500)
				{
					if(dj=1)
					{
						printf("You bought a dagger, the damage is increased by ten, and the repeated purchase is invalid.\n");
						eak=10;
						p=p+eak;//wepeon + attack 
						dj=0;
						wq=0;
					}
					else
					{
						printf("You have already purchased\n");
					}
				}
				else
				{
					printf("not enough gold\n");	
				}
				 wq=0;
				}
				while(wq==2)
				{
				if(gd>2000)
				{
					if(cj=1)
					{
						printf("You bought a long sword, damage plus 30, repeated purchase is invalid\n");
						eak=30;
						p=p+eak;//wepeon + attack 
						cj=0;
					}
					else
					{
						printf("You have already purchased\n");
					}
				}
				else
				{
					printf("not enough gold\n");
				}
				wq=0;
				}
			}
		}
}
 void fjshop(void)//arm shop
{
		while(viz==2)
		{   int fj=0,bj=1,szj=1;
			printf("Hello Warrior, welcome to the armor store\n what do you need \n1    Cloth  (damage offset 4) 500 gold \n2  chain armor (damage offset 7) 1000 gold\n3  exit the armor store\n");
			scanf("%d",&fj);
			if(fj>2)
			{
				while(fj>3)
				{
					printf("not now\n");
					fj=0;
					
				}
				while(fj==3)
				{
					printf("quit\n;");
					viz=0;
					fj=0;
				}
			}
			else
			{
				while(fj==1)
				{
				if(gd>500)
				{
					if(bj=1)
					{
						printf("You bought a cloth, the damage is offset 4, and the repeated purchase is invalid.\n");
						edf=4;
						bj=0;
					}
					else
					{
						printf("You have already purchased\n");
					}
				}
				else
				{
					printf("not enough gold\n");
				}
				fj=0;
				}
				while(fj==2)
				{
				if(gd>1000)
				{
					if(szj=1)
					{
						printf("You bought a chain armor, the damage is offset 7, and the repeated purchase is invalid.\n");
						edf=7;
						szj=0;
					}
					else
					{
						printf("You have already purchased\n");
					}
				}
				else
				{
					printf("not enough money\n");
				}
				fj=0;
				}
				
			}
		}
}
void maoxian(void)//  advanture 
{
printf("%s\n",DECISION2);
scanf("%d",&fb);
if(fb>3)
	{
		printf("not open chose again\n");
	}
else
	{
 
 switch (fb)
 
	{
 
      case 1:
    slm();
	  break;
      
	  case 2:
    slm();
    gbl();
      break;
      
	  case 3:
    slm();slm();
	gbl();  	
    gr();
      break;
 
}
}
lvup();
hp=200+20*lv;
mp=20+2*lv;
}
void slm(void) //monster 
{
  slm1();
  zdmk();
  slm2();
}
void gbl(void)
{
  gbl1();
  zdmk();
  gbl2();
}
void gr(void)
{
  gr1();
  zdmk();
  gr2();
}
void zdmk(void)//battal 
{
   while(hp>0&&tybosshp>0)
	{
    	i=1;
        printf("skill: \n1.strike  (damage %d  mp+1)\n2.bloodthirsty (mp-3)\n3. Star Burst Stream  (damage %d mp-5)\n",p,q);//待添加 
        scanf("%d",&sp);
 
        while(4<sp)
    	{
           printf("wrong skill\n");
           sp=-1;
    	}
        while(sp==1)
    	{
 
         tybosshp=tybosshp-p;
         mp++;
         printf("skrike the boss damage %d   mp ++   boss : %d hp  your mp: %d\n",p,tybosshp,mp);
         sp=0;
 
        }
 
        while(sp==2)
    	{
 
        while(mp>=3&&sp==2)
    	{
    	sh=tybosshp*0.08;
        tybosshp=tybosshp*0.92;
    	mp=mp-3;
        printf("bloodthirsty  damagme  boss%d   boss: %d hp   your mp:%d\n",sh,tybosshp,mp);
        sp=0;
		}
     
	    while(mp<3&&sp==2)
		{
        printf("mp lower 3 ,fali bloodthirsty\n");
        sp=-1;
    	}
        }
 
    	while(sp==3)
    	{
 
    	while(mp>=5&&sp==3)
        {
        tybosshp=tybosshp-q;
        mp=mp-5;
	    sp=0;
        printf("Star Burst Stream!!!  damage a lot : %d  boss hp: %d  your mp:%d\n",q,tybosshp,mp);//待定 
		}
		while(mp<5&&sp==3)
			{
				printf("mp not enough 5, XXXXX Star Burst Stream XXXXX \n");
				sp=-1;
			}
		}
    	while(tybosshp>0&&sp==0)
    	{
          if(tybosshp>hpboss*0.1)// under 10% of boss'hp, boss will wild  
	    	{
			sh=15+hp*0.01-edf;
			hp=hp-sh;
			printf("boss hit  hp -- : %d    hp : %d\n",sh,hp);
			sp=-1;
			}
        else
        {
           printf("boss go wild !!!!");
		   sh=15+hpboss*0.1-edf;// ++ attack 
		   hp=hp-sh;
		   printf("boss crazy hit hp----: %d   hp :%d\n",sh,hp); 
		   sp=-1; 
		}
		}
	}
	while(tybosshp<=0&&i==1)
	{
		printf("kill BOSS,victory！\n");
		i=i+1;
	}
	while(hp<0&&i==1)
	{
		printf("YOU WASTED，try low level quest first\n");
		i=i+2;
		getchar();
		printf("you get bless \n recover hp & mp");
		hp=200+20*lv;
		mp=20+2*lv;
	}
 
}
 

void slm1(void)
{
  printf("slime !!!!!\n");
 
  hpboss=100;//BOSS'hp
 
  tybosshp=hpboss;
}
void slm2(void)
{
if(i==2)
  {
	  printf("exe + : 20ex,gold + :50\n");
 
      ex=ex+20;
 
      gd=gd+50;
      
 	  printf("you exe:%d\n",ex);
  }
  else
  {
	  printf("still need practice\n");
  }
}
 
void gbl1(void)//goblin
{
  printf("Goblin!!!!!!\n");
 
  hpboss=300;//BOSS's hp
 
  tybosshp=hpboss;
}
void gbl2(void)//end
{
if (i==2)
 {
     printf("exe + :100ex,gold + : 200\n");
 
     ex=ex+100;
 
     gd=gd+200;
     
     printf("exe: %d\n",ex);
  }
  else
  {
	  printf("you advanture still ...\n");
  }
  }
  void gr1(void)//ghost
{
  printf("GHOST!!!!!\n");
 
  hpboss=800;//BOSS's hp 
 
  tybosshp=hpboss;
}
void gr2(void)
{
	  if(i==2)
  {
	  printf("exe + ： 300ex, gold + :500\n");
 
      ex=ex+300;
 
      gd=gd+500;
      
      printf("exe:%d\n",ex);
  }
  else
  {
	  printf("go go go !!!\n");
  }
}
