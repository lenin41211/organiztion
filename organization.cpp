#include<iostream>

class login
{
    private:
        unsigned long long int login_count=0,temp_count=0;
        struct login_structure
            {
                std::string id,user_name,password,email;
                long int created_time,login_count=0,account_count=0,profile_count=0;
                //account account_obj;
                //profile profile_obj;
            }lgn[100];
    protected:
        int add(std::string user_name,std::string password,std::string email)
        {
            temp_count=login_count;
            time_t now = time(0);
            this->lgn[login_count].created_time = stoi(std::to_string(now));
            this->lgn[login_count].id = "USR_OOO_"+std::to_string(login_count);
            this->lgn[login_count].user_name = user_name;
            this->lgn[login_count].password = password;
            this->lgn[login_count].email = email;
            this->lgn[login_count].login_count++;
            this->lgn[login_count].profile_count++;
            this->lgn[login_count].account_count++;
            login_count++;
            if(login_count == temp_count+1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            
        }
};

class account:public login
{
    private :
        unsigned long long int account_count=0,temp_count=0; 
        struct account_structure
        {
            std::string id,account_number,holder_name,email,branch,state,country;
            //std::map<long int,std::string>transaction_history;
            unsigned long long int balance,equity,account_count=0,profile_count=0,login_count=0,phone,country_code;
            //std::string account_holders_id[];
            //login login_obj;
            //profile profile_obj;

        }acc[100];
    protected:
        int add(std::string first_name,std::string last_name,long long int balance,std::string email,std::string branch,std::string state,std::string country,long int phone,long int country_code)
        {
            //struct account acc[];
                
            temp_count=account_count;     
            acc[account_count].id = "ACCOUNT_000_"+std::to_string(account_count);                           
            this->acc[account_count].account_number = "ACNT000_"+std::to_string(account_count);
            this->acc[account_count].holder_name = first_name+" "+last_name;
            this->acc[account_count].email = email;
            this->acc[account_count].branch = branch;
            this->acc[account_count].state = state;
            this->acc[account_count].country = country;
            this->acc[account_count].balance = balance;
            this->acc[account_count].phone = phone;
            this->acc[account_count].country_code = country_code;
            this->acc[account_count].account_count++;
            this->acc[account_count].profile_count++;
            this->acc[account_count].login_count++;
            account_count++; 
            if(account_count == temp_count+1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            
        }

};

class profile:protected account
{
    private:
        unsigned long long int profile_count=0,temp_count=0;
        struct profile_structure
        {
            std::string id,user_name,first_name,last_name,email,branch,state,country;
            unsigned long long int phone_number,country_code,profile_count=0,account_count=0,login_count=0;
            // login login_obj;
            // account account_obj;
            
        }pro[100];
    protected:
        int add(std::string user_name,std::string first_name,std::string last_name,std::string email,std::string branch,std::string state,std::string country,long int phone,long int country_code)
        {
                temp_count = profile_count;
                this->pro[profile_count].id = "PROFILE_000_"+std::to_string(profile_count);
                this->pro[profile_count].user_name = user_name;     
                this->pro[profile_count].first_name = first_name;                
                this->pro[profile_count].last_name = last_name;                    
                this->pro[profile_count].email = email;                            
                this->pro[profile_count].country_code = country_code;
                this->pro[profile_count].phone_number = phone;                    
                this->pro[profile_count].branch = branch;                        
                this->pro[profile_count].state = state;                            
                this->pro[profile_count].country = country;                        
                this->pro[profile_count].profile_count++;
                this->pro[profile_count].account_count++;
                this->pro[profile_count].login_count++;
                profile_count++;

            if(profile_count==temp_count+1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
              
        }
           
};

class organization:protected profile, protected account,protected login
{
         
        unsigned long long int no_of_org,org_count=0;
        
        struct organization_structure
        {
            std::string id,name,type,parent,branch,state,country;
            unsigned long long int account_count=0,profile_count=0,login_count=0;
            login login_obj;
            profile profile_obj;
            account account_obj;
        }org[100];
        
        int add()
        {
         
          //struct organization org[10];
          std::cout<<"enter the number of organization : "<<std::endl;
          std::cin>>no_of_org;
          for(int i=org_count;i<no_of_org+org_count;i++)
          {
              org[i].id = "ORGANIZATION_000_"+std::to_string(org_count);
              std::cout<<"Name of the organization : "<<std::endl;
              std::cin>>org[i].name;
              std::cout<<"Type of the organization : "<<std::endl;
              std::cin>>org[i].type;
              std::cout<<"Parent of the organization : "<<std::endl;
              std::cin>>org[i].parent;
              std::cout<<"Branch of the organization : "<<std::endl;
              std::cin>>org[i].branch;
              std::cout<<"state of the organization : "<<std::endl;
              std::cin>>org[i].state;
              std::cout<<"state of the organization : "<<std::endl;
              std::cin>>org[i].state;
              org_count++;
          }
          no_of_org+=org_count;
          if(org_count==no_of_org)
          {
              return 1;
          }
          else
          {
              return 0;
          }
          
        }

        int data_filter(int operation,std::string user_name,std::string password,std::string first_name,std::string last_name,long long int balance,std::string email,std::string branch,std::string state,std::string country,long int phone,long int country_code)
        {
            for(int i=0;i<no_of_org;i++)
            {
                if(country.compare(org[i].country)==0 )
                {
                    if(state.compare(org[i].state) == 0)
                    {
                        if(branch.compare(org[i].branch) == 0)
                        {
                            //DATA ADDITION
                            if(operation == 1)
                            {
                                org[i].login_obj.add(user_name,password,email);
                                //org[i].account_obj.add(user_name,password,email)
                                return 1;
                            }
                            //DATA UPDATION
                            else if(operation == 2)
                            {
                                return 1;
                            }
                            //DATA DELETION
                            else if(operation == 3)
                            {
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
};
int main(){

}
