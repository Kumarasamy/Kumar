#include <deque>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static enum modes
{
    FM_INVALID = 0,
    FM_VECTOR,  
    FM_DEQUE    
};    

class CVectorDequeTest  
{    
  public:
      CVectorDequeTest();    
      
      void ReadTestFile(const char* szFile, int iMode)    
      {        
          char buff[0xFFFF] = {0}; 
          std::ifstream    inFile;
          inFile.open(szFile);
          
          while(!inFile.eof())
          {
              inFile.getline(buff, sizeof(buff));
              
              if(iMode == FM_VECTOR)
                      m_vData.push_back(buff);
              else if(iMode == FM_DEQUE)
                      m_dData.push_back(buff);
          }        
          
          inFile.close();
          
       }    
       
       virtual ~CVectorDequeTest(); 
  
  protected:    
      std::vector<std::string> m_vData;    
      std::deque<std::string> m_dData;
 }; 

