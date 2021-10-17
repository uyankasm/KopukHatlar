#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct{
	char id[20];
	char x1[20];
	char x2[20];
	char y1[20];
	char y2[20];
	double did;
	double dx1;
	double dx2;
	double dy1;
	double dy2;
}Ind;

typedef struct{
	char id[20];
	char tip[20];
	char x1[20];
	char x2[20];
	char y1[20];
	char y2[20];
	double did;
	double dtip;
	double dx1;
	double dx2;
	double dy1;
	double dy2;
}Mus;

typedef struct{
	char id[20];
	char x1[20];
	char x2[20];
	char y1[20];
	char y2[20];
	double tid;
	double tx1;
	double tx2;
	double ty1;
	double ty2;
	double kopuk;
	
	double did;
	double dx1;
	double dx2;
	double dy1;
	double dy2;
}Hat;

Ind ind[10000];
Mus mus[10000];
Hat hat[10000];

int main(){ 
char dizi[100][100];
int t=0,z=0,y=0,m=0,mesken=0,ticari=0,sanayi=0,kn,l,s=0,w=0,temp;
float hat_uzunlugu=0,kus_ucusu=0,musteri_uzunlugu=0;
FILE *fp;
FILE *fp1;
FILE *fp2;
FILE *fp3;

//DOSYAYI OKUR
fp=fopen("IEEE_test_system_12_kopuk .txt","r");
if(fp==NULL){
	printf("Dosya acilamadi...");
}
else
printf("Dosya acildi..\n\n");

int i=0;
while(!feof(fp)){
fgets(dizi[i],100,fp);
if(dizi[i][0]=='I'){
goto a;
}
}
a:
i++;

while(!feof(fp)){
fgets(dizi[i],100,fp);
sscanf(dizi[i],"%s\t%s\t%s\t%s\t%s",ind[z].id,ind[z].x1,ind[z].y1,ind[z].x2,ind[z].y2);
ind[z].did=atof(ind[z].id);
ind[z].dx1=atof(ind[z].x1);
ind[z].dy1=atof(ind[z].y1);
ind[z].dx2=atof(ind[z].x2);
ind[z].dy2=atof(ind[z].y2);

if(dizi[i][0]=='E'){
	i++;
	goto b;
}
z++;
i++;
}
b:	

while(!feof(fp)){
fgets(dizi[i],100,fp);
if(dizi[i][0]=='M'){
goto d;
}
}
d:
i++;

while(!feof(fp)){
fgets(dizi[i],100,fp);
sscanf(dizi[i],"%s\t%s\t%s\t%s\t%s\t%s",mus[t].id,mus[t].tip,mus[t].x1,mus[t].y1,mus[t].x2,mus[t].y2);
mus[t].did=atof(mus[t].id);
mus[t].dx1=atof(mus[t].x1);
mus[t].dtip=atof(mus[t].tip);
mus[t].dy1=atof(mus[t].y1);
mus[t].dx2=atof(mus[t].x2);
mus[t].dy2=atof(mus[t].y2);

if(dizi[i][0]=='E'){
	i++;
	goto c;
}
t++;
i++;
}
c:

while(!feof(fp)){
fgets(dizi[i],100,fp);
if(dizi[i][0]=='H'){
goto e;
}
}
e:
i++;

while(!feof(fp)){
fgets(dizi[i],100,fp);
sscanf(dizi[i],"%s\t%s\t%s\t%s\t%s",hat[y].id,hat[y].x1,hat[y].y1,hat[y].x2,hat[y].y2);
hat[y].did=atof(hat[y].id);
hat[y].dx1=atof(hat[y].x1);
hat[y].dy1=atof(hat[y].y1);
hat[y].dx2=atof(hat[y].x2);
hat[y].dy2=atof(hat[y].y2);

if(dizi[i][0]=='E'){
	i++;
	goto r;
}
y++;
i++;
}
r:

for(m=0;m<y;m++){
	hat_uzunlugu+=sqrt(pow((hat[m].dx2-hat[m].dx1),2)+pow((hat[m].dy2-hat[m].dy1),2));//y hat sayýsý
}
for(m=0;m<t;m++){//t musteri sayýsý
	if(mus[m].dtip==1){
		mesken++;
	}
	if(mus[m].dtip==2){
		ticari++;
	}
	if(mus[m].dtip==3){
		sanayi++;
	}
}

printf("<<%d hat %.2f m\n",y,hat_uzunlugu);
printf("<<%d musteri %d mesken %d ticari %d sanayi\n\n",t,mesken,ticari,sanayi);
printf("Bilgilerini ogrenmek istediginiz hattin kimlik numarasini giriniz: ");
scanf("%d",&kn);
for(m=0;m<y;m++){//y hat sayýsý-id kaçýncý sýrada kontrol edilir
	if(hat[m].did==kn){
		l=m;
		goto h;
	}
}
h:
printf("<<Hat %d,koordinat bilgileri(%.2f,%.2f,%.2f,%.2f)\n\n",kn,hat[l].dx1,hat[l].dy1,hat[l].dx2,hat[l].dy2);
printf("Bilgilerini ogrenmek istediginiz musterinin kimlik numarasini giriniz:");
scanf("%d",&kn);

for(m=0;m<t;m++){
	if(mus[m].did==kn){
		l=m;
		goto j;
	}
}
j:
printf("<<Musteri %d,%.0f ,koordinat bilgileri(%.2f,%.2f,%.2f,%.2f)\n\n",kn,mus[l].dtip,mus[l].dx1,mus[l].dy1,mus[l].dx2,mus[l].dy2);

printf("Bilgilerini ogrenmek istediginiz indiricinin kimlik numarasini giriniz:");
scanf("%d",&kn);

for(m=0;m<z;m++){
	if(ind[m].did==kn){
		l=m;
		goto x;
	}
}
x:
printf("<<Indirici %d,koordinat bilgileri(%.2f,%.2f,%.2f,%.2f)\n\n",kn,ind[l].dx1,ind[l].dy1,ind[l].dx2,ind[l].dy2);

//KUÞ UÇUÞUNU HESAPLAR
fp1=fopen("Musteri_kus_ucusu_mesafe.txt","w");
fputs("ID\tTIP\tKUS_UCUSU_MESAFE\n",fp1);
for(m=0;m<t;m++){//t musteri sayýsý
	kus_ucusu=sqrt(pow((mus[m].dx1-ind[0].dx1),2)+pow((mus[m].dy1-ind[0].dy1),2));
	fprintf(fp1,"%.0f\t%.0f\t%.2f\n",mus[m].did,mus[m].dtip,kus_ucusu);
}

//KOPUK HATLARI KONTROL EDER
int flag = 0 ;
fp3=fopen("Kopuk_Hat.txt","w");
fprintf(fp3,"KOPUK HATLAR:\n");

	for(s=0;s<y-1;s++){//y hat sayýsý
		flag=0;
		for(w=0;w<y;w++){
			if(hat[s].dx2==hat[w].dx1&&hat[s].dy2==hat[w].dy1){
				if(s==w){
					continue;
				}	
				else{
			
					flag = 1 ;
					goto q;
				}
			}	
		}
		q:
		if(flag==0){
				fprintf(fp3,"%.0f\n",hat[s].did);	
			}
	}
	
	
/*
//HAT SIRASINI KONTROL EDER	

fp2=fopen("hat_sirasi.txt","w");
//HAT SIRALAMA
printf("Lutfen id numaranizi giriniz:");
scanf("%f",&temp);
for(m=0;m<t;m++){
	if(mus[m].did==temp){
		temp=m;
		break;
	}
}
hat[0].tx1=mus[temp].dx1;
hat[0].tx2=mus[temp].dx2;
hat[0].ty1=mus[temp].dy1;
hat[0].ty2=mus[temp].dy2;

	
	for(m=0;m<y;m++){
		if(hat[0].tx1==hat[m].dx1&&hat[0].ty1==hat[m].dy1){
			
		fprintf(fp2,"%.0lf\n",hat[m].did);
		hat[0].tx1=hat[m].dx1;
		hat[0].ty1=hat[m].dy1;	
	}
	}
	for(m=0;m<y;m++){
	    if(hat[0].tx2==hat[m].dx2&&hat[0].ty2==hat[m].dy2){
	    	
		fprintf(fp2,"%f\n",hat[m].did);
		hat[0].tx2=hat[m].dx2;
		hat[0].ty2=hat[m].dy2;	
	}
	}
	for(m=0;m<y;m++){
	    if(hat[0].tx1==hat[m].dx1&&hat[0].ty2==hat[m].dy2){
	    		
		fprintf(fp2,"%f\n",hat[m].did);
		hat[0].tx1=hat[m].dx1;
		hat[0].ty2=hat[m].dy2;	
	}
	}
	for(m=0;m<y;m++){
	    if(hat[0].tx2==hat[m].dx2&&hat[0].ty1==hat[m].dy1){
	    	
		fprintf(fp2,"%f\n",hat[m].did);
		hat[0].tx2=hat[m].dx2;
		hat[0].ty1=hat[m].dy1;	
	}
	}
	fclose(fp2);
*/


fclose(fp);
fclose(fp1);
fclose(fp3);
return 0; 
}

	
