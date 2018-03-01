#include<bits/stdc++.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include<semaphore.h>
using namespace std;
string name;
void* read(void* arg)
{

while(true)
{char buffer[20];
string tmp="./"+name;
int fd=open(tmp.c_str(),O_RDONLY);
read(fd,buffer,20);
string prn(buffer);
cout<<"reading "<<prn<<endl;//here it is printing "reading garbage value"
close(fd);
}

}
void* write(void* arg)
{
while(true)
{
string tmp="./serverx",msg;
int fd=open(tmp.c_str(),O_WRONLY);
cout<<"enter any message "<<endl;
cin>>msg;
msg="2"+name+msg;
write(fd,msg.c_str(),msg.length());
close(fd);
}

}
int main(int argc,char* argv[])
{
	int fd1;
pthread_t pr,pw;
		
string perm;
		cout<<"enter the client name "<<endl;
		cin>>name;
		perm="1"+name;
		fd1=open("./serverx",O_WRONLY);
	write(fd1,perm.c_str(),perm.length());
close(fd1);
       pthread_create(&pr,NULL,read,NULL);
	pthread_create(&pw,NULL,write,NULL);
 	pthread_join(pr,NULL);
	pthread_join(pw,NULL);
return 0;


}
