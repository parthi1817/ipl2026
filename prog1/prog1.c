#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student {
    int roll;
    char name[50];
    int marks;
};
void display(int m)
{
    FILE * fp;
    struct Student s;
    
    fp=fopen("students.dat","rb");
    
        if(fp==NULL)
        {
        printf("Invalid");
        return;
    }
    
    fseek(fp,(m-1)*sizeof(struct Student),SEEK_SET);
    fread(&s,sizeof(struct Student),1,fp);
    printf("Record %d details: ",m);
    printf("Students name:%s\t\n",s.name);
    printf("Students roll number:%d\t\n",s.roll);
    printf("Students marks:%d\t\n",s.marks);
    fclose(fp);
}
void deletek(int rollNo)
{
    FILE*fp,*temp;
    struct Student s;
    fp=fopen("students.dat","rb");
    temp=fopen("temp.dat","wb");
    if(fp==NULL || temp==NULL)
    {
        printf("Invalid");
        return;
    }
    while(fread(&s,sizeof(struct Student),1,fp))
    {
        if(s.roll!=rollNo)
        {
            fwrite(&s,sizeof(struct Student),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("students.dat");
    rename("temp.dat","students.dat");
    printf("record deleted successfully\t\n");
    
}
int main()
{ 
    FILE *fp;
    struct Student s;
    int n,m,rollNo;
    fp=fopen("students.dat","wb");
    if(fp==NULL)
    {
        printf("Invalid");
        return 0;
    }
    
    
    printf("Enter number of records:\t\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Student %d details:\t\n",i+1);
        printf("Roll number:\t\n");
        scanf("%d",&s.roll);
        printf("Name:\t\n");
        scanf("%s",s.name);
        printf("marks:\t\n");
        scanf("%d",&s.marks);
        fwrite(&s,sizeof(struct Student),1,fp);
    }
    fclose(fp);
    printf("Enter record number to display:\t\n");
    scanf("%d",&m);
    display(m);
    printf("Enter roll no to delete:\t\n");
    scanf("%d",&rollNo);
    deletek(rollNo);
    return 0;
}
