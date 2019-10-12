#include<iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

class init 
{      
    private:
        int no_of_org,profile_count=0,account_count=0,user_count=0,org_count=0; 
        string func_init;
        
        //connection C;
        
        struct user
        {
            std::string user_name,password,email,privilege;
            long int created_time,user_count=0; 
        }usr[100];

        struct account
        {
            std::string id,account_number,holder_name,email,branch,state,country;
            long long int balance,equity,account_count=0,profile_count=0;
            std::string account_holders_id[100];
            //struct user usr[];
        }acc[100];

        struct profile
        {
            std::string id,user_name,first_name,last_name,email,branch,state,country;
            long int phone_number,country_code,profile_count=0,account_count=0,user_count=0;
            //struct account acc[];
        }pro[100];

        struct organization
        {
            std::string id,name,type,parent,branch,state,country;
            long long int account_count=0,profile_count=0,user_count=0;
            //struct profile pro[];
        }org[100];

    public :
        void onStart()
        {
            try
            {
                connection C("dbname = postgres user = postgres password = Ctpl@789 \
                hostaddr = 127.0.0.1 port = 5432");

                if (C.is_open()) {
                    cout << "Opened database successfully: " << C.dbname() << endl;
                } else {
                    cout << "Can't open database" << endl;
                }

                func_init = "SELECT * from user";
                
                /* Create a non-transactional object. */
                
                nontransaction N(C);
                result R( N.exec( func_init ));

                /* List down all the records */
                for (result::const_iterator c = R.begin(); c != R.end(); ++c) {
                    // cout << " usename = " << c[0].as<string>() << endl;
                    // cout << " password = " << c[1].as<string>() << endl;
                    // cout << " Email = " << c[2].as<string>() << endl;
                    // cout << " previlege_level = " << c[3].as<string>() << endl;

                    usr[user_count].user_name = c[0].as<string>();
                    usr[user_count].password = c[1].as<string>();
                    usr[user_count].email = c[2].as<string>();
                    usr[user_count].privilege = c[3].as<string>();
                    user_count++;
                }

            } catch (const std::exception &e)
                {
                    cerr << e.what() << std::endl;
                }
        }
        
};
int main()
{
    init in;
    in.onStart();
}