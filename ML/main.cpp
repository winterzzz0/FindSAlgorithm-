/***********************************************
    Author: Abdulrhman Al-wehaib

    Machine learning Algorithm find S

    ****https://www.geeksforgeeks.org/ml-find-s-algorithm****

 ***********************************************/



#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cout;
using std::cin;
class FindSAlgorithm
{
private:
    //attributes
    size_t totalNumOfAttributes {0};
    vector<vector<string>> trainingData ;
    vector<string> specificHypothesis;
    
    
    // methods
    void computeNumOfAttributes(){
        totalNumOfAttributes = trainingData.at(0).size() -1;
    }
    void initializeHypothesis(){
       for(size_t i {0}; i<totalNumOfAttributes; i++){
           specificHypothesis.push_back("N");
       }
    }
    public:
        
    void runFindSAlgorithm(){
       computeNumOfAttributes();
       initializeHypothesis();
        for(size_t i {0}; i<trainingData.size();i++){
            for(size_t j {0}; j<trainingData.at(i).size();j++){
                if((trainingData.at(i)).at(trainingData.at(0).size()-1) == "Yes"){
                    if(j != totalNumOfAttributes){
                        if(trainingData.at(i).at(j) != specificHypothesis.at(j) && specificHypothesis.at(j) == "N"){
                            specificHypothesis.at(j) = trainingData.at(i).at(j);
                        }
                        else if(trainingData.at(i).at(j) != specificHypothesis.at(j)){
                            specificHypothesis.at(j) = "?";
                        }
                    }
                    
                }
            }
        }
    }
    
   void inputInstances(){
       size_t attributes {};
       size_t instances {};
       cout << "How many attributes? : ";
       cin >> attributes ;
       
       cout << "\nHow many instances? : ";
       cin >> instances;
       
       
       for(size_t instanceIndex {0}; instanceIndex<instances;instanceIndex++){
           vector<string> attributeValues {};
            for(size_t attributeIndex {1}; attributeIndex<=attributes;attributeIndex++){
                
                string attributeValue {};
                cout << "Attribute value " << attributeIndex << " : ";
                cin >> attributeValue;
                attributeValues.push_back(attributeValue);
            }
            
            bool invalidInput {true};
       while(invalidInput){
           char targetClass;
            cout << "the target class y/n? : ";
            cin >> targetClass;
            if(targetClass == 'y'){
                attributeValues.push_back("Yes");
                invalidInput = false;
            }else if (targetClass == 'n'){
                attributeValues.push_back("No");
                invalidInput = false;
            }else{
                cout << "provid valid answer " ;
            }
       }
       
            
       
    trainingData.push_back(attributeValues);
}
       
   }
   
   void printHypothesis(){
       cout << '<';
       for(string val : specificHypothesis){
           
           cout<< " " << val << " ";
       }
       cout << '>';
   }
};

int main(){

    \
    
    
    return 0;
}