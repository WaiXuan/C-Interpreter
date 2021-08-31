# include <iostream>
# include <string>
# include <vector>
# include <stdio.h>
# include <stdlib.h>
# include <sstream>
# include <iomanip>
# include <string.h>
# include <math.h>
using namespace std ;

enum Type {
  FIRST = 0,  
  INT = 1,
  FLOAT = 2,
  STRING = 3, 
  DOT = 4,      
  SIGN = 5,
  LP = 6,
  RP = 7,
  PERIOD = 8,
  DEF = 9,
  SYMBOL = 10,  
  QUOTE = 11,
  IGNORE = 12,
  UNDEF = 13,
  COMMAND = 14,
  CONSTANT = 15,
  TYPE = 16,
  DONE = 17,
  PM = 18,
  NO_MORE   
} ;

struct Token {
  string value ;
  double num ;
  Type type ;
  int line ;
  int column ;
} ;

struct TokenID {
  string name ;
  string type ;
  string index ;
  string data[100] ;  
  double num[100] ;
} ;

struct FunctionID {
  string name ;
  string type ;
  vector<string> index ;  
} ;

struct Anslist {
  string name ;
  int anscase ;
} ;

struct Namelist {
  string name ;  
  string type ;  
  string index ;   
  vector<TokenID> token_id ;
  vector<FunctionID> function_id ;  
  
} ;

struct Calculate {
  string value ;
  double num ;
  int index_num ; 
  string name ;  
  string type ;
  bool inverse ;
} ;

struct Ans {
  string value ;
  double num ;
} ;

struct PP_MM {
  Calculate now_data ;
  string operate ;
} ;

class Scanner {
private:
  Token mCur_token ;
  int mLine ;
  int mColumn ;  
public:
  Token PeekToken() ;
  Token GetToken() ;
  bool CharIsDigit( char temp_char ) ;
  bool CharIsStr( char temp_char, Type & type ) ;
  bool CharIsFloat( char temp_char, Type & type ) ;
  bool CharIsSign( char temp_char ) ;
  bool CharIsSymbol( char temp_char ) ;
  bool CharIsUndef( char temp_char ) ;  
  bool IsQuit( string str ) ;    
  void Reset() ;
  void Reset2() ;  
  void Clearcur_token() ;
  
} ;

class Syntax {
private:
  Scanner mScanner ;
public: 
  bool Readtoken( Token & token, Calculate & now_data, string & errorMsg,
                  Token & now_token, int & levelnum ) ;
  bool User_input( Token & token, Calculate & now_data, string & errorMsg,
                   Token & now_token, int & levelnum  ) ;
  bool Definition( Token & token, Calculate & now_data, string & errorMsg,
                   Token & now_token, int & levelnum  ) ;  
  bool Type_specifier( Token token ) ;  
  bool Function_definition_or_declarators( Token & token, Calculate & now_data, 
                                           string & errorMsg, Token & now_token,
                                           string & index, int & levelnum  ) ;
  bool Rest_of_declarators( Token & token, Calculate & now_data, string & errorMsg,
                            Token & now_token, string & index, int & levelnum ) ;
  bool Function_definition_without_ID( Token & token, Calculate & now_data,
                                        string & errorMsg, Token & now_token, int & levelnum  ) ;
  bool Formal_parameter_list( Token & token, Calculate & now_data, string & errorMsg,
                              Token & now_token, int & levelnum  ) ;
  bool Compound_statement( Token & token, Calculate & now_data, string & errorMsg,
                           Token & now_token, int & levelnum ) ;
  bool Declaration( Token & token, Calculate & now_data, string & errorMsg,
                    Token & now_token, int & levelnum ) ;  
  bool Statement( Token & token, Calculate & now_data, string & errorMsg,
                  Token & now_token, int & levelnum ) ;
  bool Expression( Token & token, Calculate & now_data, string & errorMsg,
                   Token & now_token, int & levelnum ) ;
  bool Basic_expression( Token & token, Calculate & now_data, string & errorMsg,
                         Token & now_token, int & levelnum  ) ;
  bool Rest_of_Identifier_started_basic_exp( Token & token, Calculate & now_data, string & errorMsg,
                                             Token & now_token, int & levelnum  ) ;
  bool Rest_of_PPMM_Identifier_started_basic_exp( Token & token, Calculate & now_data,
                                                  string & errorMsg, Token & now_token, int & levelnum  ) ;
  bool Sign( Token & token, Calculate & now_data, string & errorMsg,
             Token & now_token, int & levelnum  ) ;  
  bool Actual_parameter_list( Token & token, Calculate & now_data,
                              string & errorMsg, Token & now_token, int & levelnum ) ;
  bool Assignment_operator( Token & token ) ;
  bool Romce_and_romloe( Token & token, Calculate & now_data, string & errorMsg,
                         Token & now_token, int & levelnum ) ;
  bool Rest_of_maybe_logical_OR_exp( Token & token, Calculate & now_data,
                                     string & errorMsg, Token & now_token, int & levelnum ) ;
  bool Maybe_logical_AND_exp( Token & token, Calculate & now_data, string & errorMsg,
                              Token & now_token, int & levelnum ) ;
  bool Rest_of_maybe_logical_AND_exp( Token & token, Calculate & now_data,
                                       string & errorMsg, Token & now_token, int & levelnum ) ;
  bool Maybe_bit_OR_exp( Token & token, Calculate & now_data, string & errorMsg,
                         Token & now_token, int & levelnum ) ;  
  bool Rest_of_maybe_bit_OR_exp( Token & token, Calculate & now_data, string & errorMsg,
                                 Token & now_token, int & levelnum ) ;
  bool Maybe_bit_ex_OR_exp( Token & token, Calculate & now_data, string & errorMsg,
                            Token & now_token, int & levelnum ) ;
  bool Rest_of_maybe_bit_ex_OR_exp( Token & token, Calculate & now_data, string & errorMsg,
                                    Token & now_token, int & levelnum ) ;
  bool Maybe_bit_AND_exp( Token & token, Calculate & now_data, string & errorMsg,
                          Token & now_token, int & levelnum ) ; 
  bool Rest_of_maybe_bit_AND_exp( Token & token, Calculate & now_data, string & errorMsg,
                                  Token & now_token, int & levelnum ) ;
  bool Maybe_equality_exp( Token & token, Calculate & now_data, string & errorMsg,
                           Token & now_token, int & levelnum ) ;
  bool Rest_of_maybe_equality_exp( Token & token, Calculate & now_data, string & errorMsg,
                                   Token & now_token, int & levelnum ) ;
  bool Maybe_relational_exp( Token & token, Calculate & now_data, string & errorMsg,
                             Token & now_token, int & levelnum ) ;
  bool Rest_of_maybe_relational_exp( Token & token, Calculate & now_data,
                                     string & errorMsg, Token & now_token, int & levelnum ) ; 
  bool Maybe_shift_exp( Token & token, Calculate & now_data, string & errorMsg,
                        Token & now_token, int & levelnum ) ;
  bool Rest_of_maybe_shift_exp( Token & token, Calculate & now_data, string & errorMsg,
                                Token & now_token, int & levelnum ) ; 
  bool Maybe_additive_exp( Token & token, Calculate & now_data, string & errorMsg,
                           Token & now_token, int & levelnum ) ;  
  bool Rest_of_maybe_additive_exp( Token & token, Calculate & now_data, string & errorMsg,
                                   Token & now_token, int & levelnum ) ;
  bool Maybe_mult_exp( Token & token, Calculate & now_data, string & errorMsg,
                       Token & now_token, int & levelnum ) ;  
  bool Rest_of_maybe_mult_exp( Token & token, Calculate & now_data, string & errorMsg,
                               Token & now_token, int & levelnum ) ;
  bool Unary_exp( Token & token, Calculate & now_data, string & errorMsg,
                  Token & now_token, int & levelnum ) ;  
  bool Signed_unary_exp( Token & token, Calculate & now_data, string & errorMsg,
                         Token & now_token, int & levelnum ) ;
  bool Unsigned_unary_exp( Token & token, Calculate & now_data, string & errorMsg,
                           Token & now_token, int & levelnum ) ;      
  void GetNext( Token & token ) ;   
  void Define_TID( string f_name, string f_type, string f_index, int & levelnum ) ;   
  bool Find_TID( Token & token, string & errorMsg, string error_f, int & levelnum ) ;
  void Define_FID( string f_name, string f_type, int & levelnum ) ;   
  bool Find_FID( Token & token, string & errorMsg, string error_f, int & levelnum ) ;  
  void PrintAns( Token & token, Calculate & now_data, bool & isExit, int & levelnum ) ;
  void Errortype( Token & token, string & errorMsg, string error_f ) ;
  void New_namelist() ; 
  void Debug1( Calculate now_data, string error_f, Token token ) ;
  void Debug3() ;  
  void ListAllVariables() ; 
  void ListAllFunctions() ;
  void ListVariable( string name ) ; 
  void ListFunction( string name ) ;  
  void Reset() ;
  void Reset2() ;  
  void InsertData( string idname,  Calculate now_data, int index_num ) ;
  void Get_data( Token & token, Calculate & now_data, int index_num ) ;
  void Get_data2( Calculate & now_data, int index_num ) ;
  void New_Ans( Calculate & now_data ) ;
  string D_to_S( double num ) ;
  Token mnewtoken ;
  vector<Token> m_function_index ;
  vector<Namelist> m_namelist ;  
  vector<Anslist> m_anslist ;
  vector<Anslist> m_ans_fun ;  
  vector<Ans> m_ans_data ;
  vector<PP_MM> m_pp_mm ; 
  string m_ansid ;
  string m_anstype ;
  string m_f_name ;
  string m_f_type ;
  int m_anscase, m_brackets ;  
  int m_name_index ;
  bool m_levelplus ;
  bool m_cout ;
 
} ;

int main() {
  char gTestnum ;
  string errorMsg = "" ;
  bool isExit = false, isCurrent = false ;
  vector<Token> list ;   
  Type finaltype ;
  int i = 0;
  Syntax syntax ;
  Token token ;
  gTestnum = cin.get() ;
  cin.get() ;
  syntax.Reset() ;
  syntax.New_namelist() ;
  cout << "Our-C running ..." << endl  ;
  while ( ! isExit  ) {
    Token token, now_token ;
    Calculate now_data ;
    errorMsg = "" ;
    int levelnum = 0 ;
    isCurrent = syntax.Readtoken( token, now_data, errorMsg, now_token, levelnum ) ;
    if ( isCurrent ) {
      syntax.PrintAns( token, now_data, isExit, levelnum ) ;
      char temp_char ;   
      temp_char = cin.peek() ;        
      while ( temp_char == ' ' || temp_char == '\t' ) {
        cin.get() ;       
        temp_char = cin.peek() ; 
      } // while             
      
      if ( temp_char == '\n' || temp_char == '/' )  {
        syntax.Reset2() ;
      } // if 
      else {        
        syntax.Reset() ;
      } // else 
      
      
    } // if
    else {
      cout << "> " << errorMsg << endl ;      
      syntax.Reset() ;
      
    } // else
    
    errorMsg = "" ;

    i++ ;
    list.clear() ;
  } // while ()        

  cout << "> Our-C exited ..." << endl ;
  // system("PAUSE") ;

} // main()


  // ------------------------------------------- Syntax  -------------------------------------------

string Syntax::D_to_S( double num ) {
  string s ;
  stringstream ss( s ) ;
  ss << num ;
  ss >> s ;
  return s ;
} // Syntax::D_to_S()

void Syntax::New_Ans( Calculate & now_data ) {
  Ans tempAns ;
  if ( now_data.num != -99999 ) {
    tempAns.num = now_data.num ;
    tempAns.value = "" ;
    m_ans_data.push_back( tempAns ) ;
  } // if 
  else {
    tempAns.num = -99999 ;
    tempAns.value = now_data.value ;
    m_ans_data.push_back( tempAns ) ;
  } // else 
  
  now_data.value = "" ;
  now_data.name = "" ;
  now_data.num = -99999 ;
  now_data.inverse = false ;
  now_data.type = "" ;
  
} // Syntax::New_Ans()
  
void Syntax::Debug3() { 
  cout << "> Debug " << endl ;  
  if ( m_namelist.size() > 0 ) { 
    for ( int i = 0 ; i <  m_namelist[0].token_id.size() ; i++ ) {
      if ( m_namelist[0].token_id[i].index != "" ) {
        int range = atof( m_namelist[0].token_id[i].index.c_str() ) ;
        for ( int k = 0 ; k < range ; k++ ) {
          cout << m_namelist[0].token_id[i].name ;
          cout << "  [ " << k <<   "]" << "   type :  " ;
          cout << m_namelist[0].token_id[i].type << "   index :  " ;  
          cout << m_namelist[0].token_id[i].index << "   data :  " ;  
          cout << m_namelist[0].token_id[i].data[k] << "   num :  " ;       
          cout << m_namelist[0].token_id[i].num[k] << endl ;              
        } // for 
      } // if 
      else {    
        cout << m_namelist[0].token_id[i].name << "   type :  " ;
        cout << m_namelist[0].token_id[i].type << "   index :  " ;  
        cout << m_namelist[0].token_id[i].index << "   data :  " ;  
        cout << m_namelist[0].token_id[i].data[0] << "   num :  " ;       
        cout << m_namelist[0].token_id[i].num[0] << endl ;
      } // else 
    } // for 
  } // if 
  
} // Syntax::Debug3()

void Syntax::Debug1( Calculate now_data, string error_f, Token token ) { 
 
  //      cout << error_f << " - " << token.value << endl ;
  //      cout << "\n name : " << now_data.name << "  index_num : " << now_data.index_num ;
  //      cout << "  type : " << now_data.type << "  value : " << now_data.value ;
  //      cout << "  num : "<< now_data.num << "  inverse : " << now_data.inverse ;
  //      cout << "\n---------------------------------------------------\n\n" ;
} // Syntax::Debug1()

void Syntax::Get_data2( Calculate & now_data, int index_num ) {
  // cout << " 進Get_data  token      " << token.value  << " type :" << token.type ;
  // cout << " now_data.num :" << now_data.num << " value :" << now_data.value << endl ;
  now_data.index_num = index_num ;
  bool find = false ;
  for ( int i = 0; i <= m_namelist[0].token_id.size()-1 && !find ; i++ ) {  
    if ( now_data.name == m_namelist[0].token_id[i].name ) {  
      if ( now_data.type == "int" || 
           now_data.type == "float" ) {
        now_data.num = m_namelist[0].token_id[i].num[index_num] ;
        now_data.value = "" ;
        now_data.type = m_namelist[0].token_id[i].type ;
        find = true ;
      } // if 
      else {
        now_data.type = m_namelist[0].token_id[i].type ;
        now_data.value = m_namelist[0].token_id[i].data[index_num] ;
        now_data.num = -99999 ;   
        find = true ;
      } // else 
    } // if     
  } // for    
    
    
    


  // cout << " 出Get_data  token      " << token.value  << " type :" << token.type ;
  // cout << " now_data.num :" << now_data.num << " value :" << now_data.value << endl ; 
  // cout << "------------------------- \n\n" ;
} // Syntax::Get_data2()

void Syntax::Get_data( Token & token, Calculate & now_data, int index_num ) {
  // cout << " 進Get_data  token      " << token.value  << " type :" << token.type ;
  // cout << " now_data.num :" << now_data.num << " value :" << now_data.value << endl ;
  bool find = false ;
  string tempdata ;
  double reset_double ;
  now_data.index_num = 0 ;
  now_data.inverse = false ;
  if ( token.value == "cout" ) {
    now_data.value = "" ;
    now_data.name = "" ;
    // now_data.num = -99999 ;
    find = true ;
  } // if 
  else if (  token.value == "true" ||  token.value == "false" ) {
    now_data.value = token.value ;
    find = true ;
  } // else if  

    
  if ( token.type == CONSTANT && !find ) {
    now_data.num = atof( token.value.c_str() ) ;
    now_data.value = "" ;
    now_data.name = "" ;   
    find = true ;
  } // if 
  else if ( token.value[0] == '\"' && !find  ) {  
    for ( int k = 1 ; k < token.value.length()-1 ; k++ )
      tempdata = tempdata + token.value[k] ;
    if ( tempdata != "\\n" ) {  
      now_data.value = tempdata ;
      now_data.name = "" ;    
      now_data.num = -99999 ;    
    } // if 
    else {
      mnewtoken = mScanner.PeekToken() ;      
      if ( mnewtoken.value != ";" ) {
        now_data.value = tempdata ;
        now_data.name = "" ;    
        now_data.num = -99999 ;                  
      } // if 
    } // else 
    
    find = true ;
  } // else if 
  else if ( token.value[0] == '\'' && !find  ) {  
    now_data.value = token.value[1] ;
    now_data.name = "" ;
    now_data.num = -99999 ;   
    find = true ;
  } // else if 
  else if ( !find ) {
    for ( int i = 0; i <= m_namelist[0].token_id.size()-1 && !find ; i++ ) {  
      if ( token.value == m_namelist[0].token_id[i].name ) {  
        if ( m_namelist[0].token_id[i].type == "int" || 
             m_namelist[0].token_id[i].type == "float" ) {
          now_data.num = m_namelist[0].token_id[i].num[index_num] ;
          now_data.value = "" ;
          now_data.name = token.value ;
          now_data.type = m_namelist[0].token_id[i].type ;
          find = true ;
        } // if 
        else {
          now_data.type = m_namelist[0].token_id[i].type ;
          now_data.value = m_namelist[0].token_id[i].data[index_num] ;
          now_data.num = -99999 ;
          now_data.name = token.value ;          
          find = true ;
        } // else 
      } // if     
    } // for    
    
    
    
  } // else if 

  // cout << " 出Get_data  token      " << token.value  << " type :" << token.type ;
  // cout << " now_data.num :" << now_data.num << " value :" << now_data.value << endl ; 
  // cout << "------------------------- \n\n" ;
} // Syntax::Get_data()

void Syntax::InsertData( string idname, Calculate now_data, int index_num ) {
  
  if ( m_namelist.size() > 0 ) { 
    for ( int i = 0 ; i <  m_namelist[0].token_id.size() ; i++ ) {  
      if ( m_namelist[0].token_id[i].name == idname ) {       
      
        if ( m_namelist[0].token_id[i].type == "int" || 
             m_namelist[0].token_id[i].type == "float" ) {                
          m_namelist[0].token_id[i].num[index_num] = now_data.num ;
        } // if 
        else 
          m_namelist[0].token_id[i].data[index_num] = now_data.value ;
      } // if 要判斷型態 
    
    } // for  
  } // if 
  
} // Syntax::InsertData()

void Syntax::PrintAns( Token & token, Calculate & now_data, bool & isExit, int & levelnum ) {
  bool find = false ;  
  if ( token.value == "Done()" )  isExit = true ;  
  else if ( m_ans_fun.size() > 0 ) {
    if ( m_ans_fun[m_ans_fun.size()- 1].anscase == 4 ) {
      cout << "> " << "Definition of " << m_ans_fun[m_ans_fun.size()- 1].name ;
      cout << "() entered ..." << endl ;
    } // if 
    else if ( m_ans_fun[m_ans_fun.size()- 1].anscase == 5 ) {
      cout << "> " << "New definition of " << m_ans_fun[m_ans_fun.size()- 1].name ;
      cout << "() entered ..." << endl ;
    } // else if         
    
    for ( int i = 0 ; i < m_ans_fun.size()-1 && m_ans_fun.size() > 1 ; i++ ) {

      if ( m_ans_fun[i].anscase == 4 ) {
        cout << "Definition of " << m_ans_fun[i].name ;
        cout << "() entered ..." << endl ;
      } // if 
      else if ( m_ans_fun[i].anscase == 5 ) {
        cout << "New definition of " << m_ans_fun[i].name ;
        cout << "() entered ..." << endl ;
      } // else if      
                      
    } // for     
    
  } // else if 
  else if ( m_anslist.size() > 0 ) {
    if ( m_anslist[m_anslist.size()- 1].anscase == 1 ) {
      cout << "> " << "Definition of " << m_anslist[m_anslist.size()- 1].name ;
      cout << " entered ..." << endl ;
    } // if 
    else if ( m_anslist[m_anslist.size()- 1].anscase == 2 ) {
      cout << "> " << "New definition of " << m_anslist[m_anslist.size()- 1].name ;
      cout << " entered ..." << endl ;
    } // else if   
       

    
    for ( int i = 0 ; i < m_anslist.size()-1 && m_anslist.size() > 1 ; i++ ) {
      if ( m_anslist[i].anscase == 1 ) {
        cout << "Definition of " << m_anslist[i].name ;
        cout << " entered ..." << endl ;
      } // if 
      else if ( m_anslist[i].anscase == 2 ) {
        cout << "New definition of " << m_anslist[i].name ;
        cout << " entered ..." << endl ;
      } // else if
                      
    } // for 
    
  } // else if 
  else if ( token.value == "ListAllVariables()" || token.value == "ListAllFunctions()" 
            || token.value == "ListVariable()"  || token.value == "ListFunction()" )
    cout << "Statement executed ..." << endl ; 
  else {
    cout << "> " ;
    if ( m_cout ) {
      for ( int i = 0 ; i < m_ans_data.size() ; i++ ) {
        
        if ( m_ans_data[i].num != -99999 ) {
          int test = m_ans_data[i].num ;        
          if ( test == m_ans_data[i].num )  
            cout << fixed << setprecision( 0 ) <<  m_ans_data[i].num ;  
          else
            cout << fixed << setprecision( 3 ) <<  m_ans_data[i].num ;  
          
        } // if 
        // cout << fixed << setprecision( 0 ) <<  m_ans_data[i].num << endl ;
        // if (  m_ans_data[i].type )  cout << fixed << setprecision( 0 ) <<  m_ans_data[i].num << endl ;
        // else cout << fixed << setprecision( 3 ) <<  m_ans_data[i].num << endl ;        
        else {  
          for ( int k = 0 ; k < m_ans_data[i].value.length() ; k++ ) {
            if ( m_ans_data[i].value[k] == '\\' ) {
              if ( ( k + 1 ) <= m_ans_data[i].value.length() - 1 ) {      
                if ( m_ans_data[i].value[k+1] == 'n' ) {        
                  cout << endl ;
                  k++ ;
                } // if 
                else {        
                  cout << m_ans_data[i].value[k] ;
                } // else 
              } // if 
            } // if  
            else 
              cout << m_ans_data[i].value[k] ;
          } // for 
          

        } // else         
        
        
      } // for 

      cout << endl ;
    } // if 
    
    cout << "Statement executed ..." << endl ;
  } // else 
  
  if ( m_pp_mm.size() > 0 ) {  
    for ( int i = 0 ; i < m_pp_mm.size() ; i++ ) {
      if ( m_pp_mm[i].operate == "++" )
        m_pp_mm[i].now_data.num++ ;    
      else if ( m_pp_mm[i].operate == "--" )
        m_pp_mm[i].now_data.num-- ;  
      InsertData( m_pp_mm[i].now_data.name, m_pp_mm[i].now_data, m_pp_mm[i].now_data.index_num ) ;
    } // for 
  } // if
  
    
} // Syntax::PrintAns() 
  


void Syntax::Errortype( Token & token, string & errorMsg, string error_f ) {  
  if ( errorMsg == "" ) {
    // cout << "這- "<< error_f <<"  -" << token.value<< endl ;
     
    stringstream ss ;
    ss << token.line ;
    string templine ;
    ss >>  templine ;
    if ( token.type == UNDEF ) {  
      errorMsg = "Line " + templine + " : unrecognized token with first char : '"+ token.value + "'" ; 
    } // if 
    else  errorMsg = "Line " + templine + " : unexpected token : '"+ token.value + "'" ;      
    //    if ( token.type == UNDEF ) 
    //      errorMsg = error_f + "-  Line "
    //    else  errorMsg = error_f + "-  Line " 
  } // if  
} // Syntax::Errortype()
  
void Syntax::GetNext( Token & token ) {
  token = mScanner.GetToken() ;  
  m_function_index.push_back( token ) ;  
  // list.push_back( token ) ;  
} // Syntax::GetNext()

void Syntax::New_namelist() {
  m_namelist.clear() ;
  Namelist temp_name_list ;   
  temp_name_list.name = "Level-0" ;  
  m_namelist.push_back( temp_name_list ) ;    

} // Syntax::New_namelist()


void Syntax::Define_TID( string f_name, string f_type, string f_index, int & levelnum ) {
  // type 還沒使用 
  bool findname = false ;       
  Namelist temp_name_list ;    
  TokenID  temp_token_list ;   
  m_name_index = levelnum ; 
  // cout << "近來DEF_TID "<< f_name << endl ;
  //  cout << "m_namelist.size()  " << m_namelist.size() << endl ;
  //  cout << "levelnum  " << levelnum << endl ;
  // cout << "DEFID " << endl ; 
  
  while ( m_namelist.size() <  m_name_index ) {
    temp_name_list.token_id.push_back( temp_token_list ) ;     
    m_namelist.push_back( temp_name_list ) ;           
  } // while 層數不對補層數
  
  if ( m_namelist.size() == 0 || m_namelist.size() ==  m_name_index ) {  
    temp_token_list.name = f_name ;
    temp_token_list.type = f_type ;
    temp_token_list.index = f_index ;
    if ( f_index != "" ) {
      int range = atoi( f_index.c_str() ) ;
      for ( int k = 0 ; k < range ; k++ ) {
        temp_token_list.num[k] = -99999 ;
      } // for 
    } // if 
    else {
      temp_token_list.num[0] = -99999 ;
    } // else 
    
    
    temp_name_list.token_id.push_back( temp_token_list ) ;     
    m_namelist.push_back( temp_name_list ) ;     
    // cout << "LIST :  "<< m_namelist[m_name_index].token_id[0].name << endl ;
    findname = true ;
  } // if // cout << "沒東西啦" <<endl ; 

  
  for ( int i = 0 ; i < m_namelist[m_name_index].token_id.size() && !findname ; i++ ) {
    if ( m_namelist[m_name_index].token_id[i].name == f_name ) {
      findname = true ;
      m_namelist[m_name_index].token_id[i].type = f_type ;
      m_namelist[m_name_index].token_id[i].index = f_index ;
      if ( f_index != "" ) {
        int range = atoi( f_index.c_str() ) ;
        for ( int k = 0 ; k < range ; k++ ) {
          m_namelist[m_name_index].token_id[i].num[k] = -99999 ;
        } // for 
      } // if 
      else {
        m_namelist[m_name_index].token_id[i].num[0] = -99999 ;
      } // else       m_namelist[m_name_index].token_id[i].index = f_index ;
      
      
      
      m_anscase = 2 ;
    } // if 名子一樣 是 New definition
  } // for         
  
  if ( !findname ) {
    temp_token_list.name = f_name ;
    temp_token_list.type = f_type ;
    temp_token_list.index = f_index ;
    if ( f_index != "" ) {
      int range = atoi( f_index.c_str() ) ;
      for ( int k = 0 ; k < range ; k++ ) {
        temp_token_list.num[k] = -99999 ;
      } // for 
    } // if 
    else {
      temp_token_list.num[0] = -99999 ;
    } // else     

    m_namelist[m_name_index].token_id.push_back( temp_token_list ) ;            
  } // if 
  
} // Syntax::Define_TID()


void Syntax::Define_FID( string f_name, string f_type, int & levelnum ) {
  // type 還沒使用 
  bool findname = false ;       
  Namelist temp_name_list ;    
  FunctionID  temp_function_list ;   
  m_name_index = levelnum ;
  //  cout << "近來DEF_FID "<< f_name << endl ;
  //    cout << "近來levelnum "<< levelnum << endl ;
  //     cout << "近來m_namelist.size() "<< m_namelist.size() << endl ; 
  while ( m_namelist.size() <  m_name_index ) {
    temp_name_list.function_id.push_back( temp_function_list ) ;     
    m_namelist.push_back( temp_name_list ) ;           
  } // while 層數不對補層數 
  
  
  if ( m_namelist.size() ==  m_name_index ) {  
    temp_function_list.name = f_name ;
    temp_function_list.type = f_type ;
    for ( int i = 0 ; i < m_function_index.size() ; i++ ) {
      string temp_value = m_function_index[i].value ;
      temp_function_list.index.push_back( temp_value ) ;           
      
    } // for 
    
    temp_name_list.function_id.push_back( temp_function_list ) ;     
    m_namelist.push_back( temp_name_list ) ;     

    findname = true ;
  } // if // cout << "沒東西啦" <<endl ; 
  // cout << "\nm_namelist.size() " <<  m_namelist.size() << endl ;
  // cout << "m_name_index" << m_name_index << endl ;
  // cout << " m_namelist[m_name_index].function_id.size()  " 
  // cout << m_namelist[m_name_index].function_id.size() << endl ;
  for ( int i = 0 ; i < m_namelist[m_name_index].function_id.size() && !findname ; i++ ) {
    if ( m_namelist[m_name_index].function_id[i].name == f_name ) {
      findname = true ;          
      m_namelist[m_name_index].function_id.erase( m_namelist[m_name_index].function_id.begin() + i ) ;
      
      temp_function_list.name = f_name ;
      temp_function_list.type = f_type ;
      // temp_function_list.index = f_index ;
      for ( int i = 0 ; i < m_function_index.size() ; i++ ) {
        string temp_value = m_function_index[i].value ;
        temp_function_list.index.push_back( temp_value ) ;          
      } // for     
    
      m_namelist[m_name_index].function_id.push_back( temp_function_list ) ;  

      m_anscase = 5 ;
    } // if 名子一樣 是 New definition
  } // for         

  if ( !findname ) {
    temp_function_list.name = f_name ;
    temp_function_list.type = f_type ;
    // temp_function_list.index = f_index ;
    for ( int i = 0 ; i < m_function_index.size() ; i++ ) {
      string temp_value = m_function_index[i].value ;
      temp_function_list.index.push_back( temp_value ) ;           
    } // for     
    
    m_namelist[m_name_index].function_id.push_back( temp_function_list ) ;            
  } // if 
} // Syntax::Define_FID()


 
bool Syntax::Find_TID( Token & token, string & errorMsg, string error_f, int & levelnum ) {
  // 尋找已經宣告的ID 將token的值跟type替換 
  // cout << "FINDID-index " <<  m_name_index <<" -size : "<< m_namelist.size() << endl ;
  // Debug2( m_name_index ) ;
  // cout << "近來Find_TID "<< token.value << endl ; 
  bool find = false ;
  TokenID tempid ;
  m_name_index = levelnum ;
  stringstream ss ;
  ss << token.line ;
  string templine ;
  ss >>  templine ;
  // cout << " token.line : " << token.line << " templine : " << templine << endl ;   
  
  if ( token.value == "cout" || token.value == "cin" || token.value == "return" 
       || token.value == "if" || token.value == "else" || token.value == "while"
       || token.value == "do" ) return true ;
  else if ( token.value[0] == '\"' ) return true ;
  else if ( token.value[0] == '\'' ) { 
    if ( token.value[1] == '\'' && errorMsg == "" ) {  
      errorMsg = "Line " + templine + " : unrecognized token with first char : '" + token.value + "'" ;
      return false ;
    } // if
    else if ( token.value[1] == '\\' && errorMsg == "" ) {  
      if ( token.value[2] == 'n' || token.value[2] == 'r' || token.value[2] == 't' || 
           token.value[2] == '\\' || token.value[2] == '"' || token.value[2] == 'n' ) { 
         
        if ( token.value[3] != '\'' && errorMsg == "" ) {  
          errorMsg = "Line " + templine + " : unrecognized token with first char : '" 
          + token.value[3] + "'";
          return false ;          
        } // if 
        
        return true ;
      } // if     
      else {
        errorMsg = "Line " + templine + " : unrecognized token with first char : '" 
        + token.value[2] + "'";
        return false ;          
        
      } // else 
    
    } // else if 
    else if ( token.value[2] != '\'' && errorMsg == "" ) {  
    
      errorMsg = "Line " + templine + " : unrecognized token with first char : '" 
      + token.value[2] + "'";
      return false ;         
     
    } // else if 
    else return true ;
    
    
    
  } // else if    
     
    
  // cout << "m_name_index  " << m_name_index << endl ;
  for ( int index = m_name_index ; index >= 0 && !find ; index-- ) {   
    if ( m_namelist.size() > index && m_namelist[index].token_id.size() != 0 ) {    
      for ( int i = 0; i <= m_namelist[index].token_id.size()-1 && !find ; i++ ) {
        if ( token.value == m_namelist[index].token_id[i].name ) {      
          return true ; 
        } // if 
      } // for 
    } // if 
  } // for     
  

  

    
  if ( errorMsg == "" ) {
    errorMsg = "Line " + templine + " : undefined identifier : '" + token.value + "'";
    // errorMsg = error_f +"-Line " + templine + " : undefined identifier : '" + token.value + "'";
  } // if 
  
  // error_f +
  return false ;
} // Syntax::Find_TID()


bool Syntax::Find_FID( Token & token, string & errorMsg, string error_f, int & levelnum ) {
  // 尋找已經宣告的ID 將token的值跟type替換 
  // cout << "FINDID-index " <<  m_name_index <<" -size : "<< m_namelist.size() << endl ;
  // Debug2( m_name_index ) ;
  // cout << "近來Find_FID "<< token.value << endl ;
  bool find = false ;
  m_name_index = levelnum ;
  TokenID tempid ;
  stringstream ss ;
  ss << token.line ;
  string templine ;
  ss >>  templine ;
  // cout << " token.line : " << token.line << " templine : " << templine << endl ;   
  
  if ( token.value == "cout" || token.value == "cin" || token.value == "return" 
       || token.value == "if" || token.value == "else" || token.value == "while"
       || token.value == "do" ) return true ;
  else if ( token.value[0] == '\"' ) return true ;
  else if ( token.value[0] == '\'' ) { 
    if ( token.value[1] == '\'' && errorMsg == "" ) {  
      errorMsg = "Line " + templine + " : unrecognized token with first char : '" + token.value + "'" ;
      return false ;
    } // if
    else if ( token.value[1] == '\\' && errorMsg == "" ) {  
      if ( token.value[2] == 'n' || token.value[2] == 'r' || token.value[2] == 't' || 
           token.value[2] == '\\' || token.value[2] == '"' || token.value[2] == 'n' ) { 
         
        if ( token.value[3] != '\'' && errorMsg == "" ) {  
          errorMsg = "Line " + templine + " : unrecognized token with first char : '" 
          + token.value[3] + "'";
          return false ;          
        } // if 
        
        return true ;
      } // if     
      else {
        errorMsg = "Line " + templine + " : unrecognized token with first char : '" 
        + token.value[2] + "'";
        return false ;          
        
      } // else 
    
    } // else if 
    else if ( token.value[2] != '\'' && errorMsg == "" ) {  
    
      errorMsg = "Line " + templine + " : unrecognized token with first char : '" 
      + token.value[2] + "'";
      return false ;         
     
    } // else if 
    else return true ;
    
    
    
  } // else if    
     
    
  // cout << "m_name_index  " << m_name_index << endl ;
  for ( int index = m_name_index ; index >= 0 && !find ; index-- ) {   
    if ( m_namelist.size() > index && m_namelist[index].function_id.size() != 0 ) {    
      for ( int i = 0; i <= m_namelist[index].function_id.size()-1 && !find ; i++ ) {
        if ( token.value == m_namelist[index].function_id[i].name ) {      
          return true ; 
        } // if 
      } // for 
    } // if 
  } // for     
  

  

    
  if ( errorMsg == "" ) {
    errorMsg = "Line " + templine + " : undefined identifier : '" + token.value + "'";
    // errorMsg = error_f +"Line " + templine + " : undefined identifier : '" + token.value + "'";    
  } // if 
  // error_f +
  return false ;
} // Syntax::Find_FID()







bool Syntax::Readtoken( Token & token, Calculate & now_data,
                        string & errorMsg, Token & now_token, int & levelnum ) { 
  
  m_anslist.clear() ;
  m_ans_fun.clear() ;
  m_levelplus = false ;
  m_cout = false ;
  if ( User_input(  token, now_data, errorMsg, now_token, levelnum ) ) return true ;
  else {    
    // 文法錯誤 將這行全部讀掉 
    mScanner.Clearcur_token() ;    
    char temp_char ;     
    temp_char = cin.peek() ;
    bool find = false ;
    while ( !find ) {
      temp_char = cin.get() ;   
      if ( temp_char == '\n' ) 
        find = true ;
      else   
        temp_char = cin.peek() ;
    } // while 

    if ( errorMsg == "" ) {
      errorMsg = "error - Readtoken "  ;
    } // if
    
    return false ;
  } // else         
       
} // Syntax::Readtoken()  
                                
bool Syntax::User_input( Token & token, Calculate & now_data,
                         string & errorMsg, Token & now_token, int & levelnum ) {
  // ( definition | statement ) { definition | statement }
  // 未定義 與 已定義直接去statement執行      迴圈還沒寫 
  string error_f = "User_input" ;
  mnewtoken = mScanner.PeekToken() ;
  // cout << "最初  "<< mnewtoken.value << "  " <<  mnewtoken.line << endl ;
  string tempvalue = mnewtoken.value ;
  if (  mnewtoken.value == "Done" || mnewtoken.value == "ListAllVariables" ||
       mnewtoken.value == "ListAllFunctions" || mnewtoken.value == "ListVariable" 
       || mnewtoken.value == "ListFunction" || mnewtoken.value == "Debug"  ) {         
    GetNext( token ) ;
    // cout << "User_input-Done-1  "<< token.value << "\n" ;       
    mnewtoken = mScanner.PeekToken() ;   
    if ( mnewtoken.value == "(" ) {      
      string tempfind ;
      GetNext( mnewtoken ) ;  
      token.value = token.value + mnewtoken.value ;
      // cout << "User_input-Done-2  "<< token.value << "\n" ;   
      if ( tempvalue == "ListVariable" || tempvalue == "ListFunction" ) {
        mnewtoken = mScanner.PeekToken() ;  
        if ( ( mnewtoken.type == STRING && mnewtoken.value[0] == '\"' ) || 
             mnewtoken.type == CONSTANT ) {        
          GetNext( mnewtoken ) ;
          tempfind = mnewtoken.value ;
        } // if 
        else {
          if ( Find_TID( mnewtoken, errorMsg, error_f, levelnum ) )
            errorMsg = "Line 1 : Para Num Error" ;
          return false ;      
        } // else 
        
      } // if 
      
      mnewtoken = mScanner.PeekToken() ;           
      if ( mnewtoken.value == ")" ) {
        GetNext( mnewtoken ) ;  
        token.value = token.value + mnewtoken.value ;
        if ( tempvalue == "Done" ) token.type = DONE ;
        else {  
          mnewtoken = mScanner.PeekToken() ;
          if ( mnewtoken.value != ";" ) {      
            Errortype( mnewtoken, errorMsg, error_f ) ;
            return false ;
          } // if 
          
          GetNext( mnewtoken ) ;  
    
          if ( tempvalue == "ListAllVariables" ) {
            ListAllVariables() ;
          } // if 
          else if ( tempvalue == "ListAllFunctions" ) {
            ListAllFunctions() ;
          } // else if 
          else if ( tempvalue == "ListVariable" ) {
            ListVariable( tempfind ) ; 
          } // else if 
          else if ( tempvalue == "ListFunction" ) {
            ListFunction( tempfind ) ;
          } // else if   
          else if ( tempvalue == "Debug" ) {
            Debug3() ;
          } // else if             
        } // else if 
        // cout << "User_input-Done-3  "<< token.value << "\n" ;  
        return true ;
      } // if Done結束
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ; 
      } // else 
    } // if Done讀近來判斷是否有左右括號 
    else {
      if ( Statement( token, now_data, errorMsg, now_token, levelnum ) ) {
        return true; 
      } // if 
      else  return false ;
    } // else 
  }  // if     



  else if ( mnewtoken.value == "int" || mnewtoken.value == "char" || mnewtoken.value == "float"
            || mnewtoken.value == "string" || mnewtoken.value == "bool" || mnewtoken.value == "void" ) {
    GetNext( token ) ;
    // cout << "最初 -2 "<< token.value << "  " <<  token.line << endl ;
    // cout << "User_input-1  "<< token.value << "\n" ;     
    if ( Definition( token, now_data, errorMsg, now_token, levelnum ) ) {
      if ( m_anscase == -1 ) m_anscase = 1 ;
      return true ;
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;
    } // else 
  } // else if 
  else {
    GetNext( token ) ; 
    // cout << "User_input-2  "<< token.value << "\n" ;
    if ( Statement( token, now_data, errorMsg, now_token, levelnum ) ) {
      m_anscase = 3 ;
      return true ;
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;
    } // else    
  } // else 
                                       
} // Syntax::User_input()     

bool Syntax::Definition( Token & token, Calculate & now_data, string & errorMsg, Token & now_token,
                         int & levelnum ) {
  // VOID ID function definition without ID 
  // | type specifier ID function definition or declarators
  // 
  string error_f = "Definition" ;
  mnewtoken = mScanner.PeekToken() ;
  string f_name, f_type ;
    
  if ( mnewtoken.type == STRING ) {
    m_f_type = token.value ;
    // peeknewtoken 判斷是否是ID 再利用上面傳下來token判斷function 
    if ( token.value == "void" ) {
      Anslist temp_anslist ; 
      f_type = token.value ;      
      GetNext( token ) ; 
      m_f_name = token.value ;
      temp_anslist.name = token.value ;
      f_name = token.value ;
      if ( token.value[0] == '\"' ) { 
        bool end = false ;
        string error_str ;
        for ( int i = 1 ; !end ; i++ )  {
          if ( token.value[i] == '\"' ) {      
            end = true ;
          } // if 
          else {
            error_str = error_str + token.value[i] ;
          } // else 
        } // for   
        
        token.value = error_str ;
        Errortype( token, errorMsg, error_f ) ;
        return false ;
      } // if  判斷是否是"123"之類的東西      
      
      mnewtoken = mScanner.PeekToken() ;
      if ( mnewtoken.value != "(" ) {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;
      } // if 
      
      GetNext( token ) ;
      // cout << "Definition-1  "<< token.value << "\n" ;      
      // cout << "DEF1-levelnum" <<  levelnum  << endl ;
      if ( Function_definition_without_ID( token, now_data, errorMsg, now_token, levelnum ) ) {
        m_anscase = 4 ;
        Define_FID( f_name, f_type, levelnum ) ;  
        temp_anslist.anscase = m_anscase ;
        m_ans_fun.push_back( temp_anslist ) ;  
        // cout << "DEF2-levelnum" <<  levelnum  << endl ;                  
        return true ;
      } // if 
      else {
        // cout << "DEF3-levelnum" <<  levelnum  << endl ;  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;
      } // else            
    } // if 定義function 
    
    
    
    else if ( Type_specifier( token ) ) {  
      Anslist temp_anslist ;      
      m_anstype = token.value ;     
      f_type = token.value ;            
      GetNext( token ) ;   
      m_f_name = token.value ;
      temp_anslist.name = token.value ;
      f_name = token.value ;
      if ( token.value[0] == '\"' ) { 
        bool end = false ;
        string error_str ;
        for ( int i = 1 ; !end ; i++ )  {
          if ( token.value[i] == '\"' ) {      
            end = true ;
          } // if 
          else {
            error_str = error_str + token.value[i] ;
          } // else 
        } // for   
        
        token.value = error_str ;
        Errortype( token, errorMsg, error_f ) ;
        return false ;
      } // if  
      
      m_ansid = token.value ;
      string index ;
      // cout << "Definition-2  "<< token.value << "\n" ;
      // 這裡是否需要存名子 ??????? 
      if ( Function_definition_or_declarators( token, now_data, errorMsg, now_token, index, levelnum ) ) {
        // cout << "m_anscase-1 :  " << m_anscase << endl ;
        if ( m_anscase == 1 || m_anscase == -1 ) {
          m_anscase = 1 ;
          Define_TID( f_name, f_type, index, levelnum ) ;  
          temp_anslist.anscase = m_anscase ;
          m_anslist.push_back( temp_anslist ) ;
          m_anscase = 1 ;
        } // if 
        else if ( m_anscase == 4 || m_anscase == 5 ) {
          
          Define_FID( f_name, f_type, levelnum ) ;  
          // cout << " m_anscase " << m_anscase << endl;
          temp_anslist.anscase = m_anscase ;
          m_ans_fun.push_back( temp_anslist ) ;
                
        } // else if 
        
        return true ;
        
      } // if 文法正確將ID存起來 
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;
      } // else      
      
    } // else if 定義變數 
  } // if 是ID
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;
  } // else
  
  Errortype( mnewtoken, errorMsg, error_f ) ;
  return false ; // 這裡注意多家的 
} // Syntax::Definition()   

bool Syntax::Type_specifier( Token token ) {
  // INT | CHAR | FLOAT | STRING | BOOL
  if ( token.value == "int" || token.value == "char" || token.value == "float"
       || token.value == "string" || token.value == "bool" ) return true ;
  else return false ;                                       
} // Syntax::Type_specifier()   

bool Syntax::Function_definition_or_declarators( Token & token, Calculate & now_data,
                                                 string & errorMsg, Token & now_token,
                                                 string & index, int & levelnum ) {
  // function_definition_without_ID | rest_of_declarators
  string error_f = "Function_definition_or_declarators" ;  
  mnewtoken = mScanner.PeekToken() ;
  if ( mnewtoken.value == "(" ) {
    GetNext( token ) ;   
    m_anscase = 4 ; 
    if ( Function_definition_without_ID( token, now_data, errorMsg, now_token, levelnum ) ) {
      return true ;
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;
    } // else   
  } // if function_definition_without_ID  
  else if ( mnewtoken.value == "[" || mnewtoken.value == "," || mnewtoken.value == ";" ) {  
    // // cout << "Function_definition_or_declarators-2"<< token.value << "\n" ;    
    if ( Rest_of_declarators(  token, now_data, errorMsg, now_token, index, levelnum  ) ) return true ;
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;
    } // else
  } // else if rest_of_declarators
  else {
    GetNext( token ) ;    
    Errortype( token, errorMsg, error_f ) ;
    return false ;
  } // else 錯誤 
  

                                       
} // Syntax::Function_definition_or_declarators()   

bool Syntax::Rest_of_declarators( Token & token, Calculate & now_data, string & errorMsg,
                                  Token & now_token, string & index, int & levelnum ) {
  //  [ '[' Constant ']' ] { ',' Identifier [ '[' Constant ']' ] } ';'
  string error_f = "Rest_of_declarators" ;    
  mnewtoken = mScanner.PeekToken() ;  
  // // cout << "Rest_of_declarators " << mnewtoken.value << endl ;     
  if ( mnewtoken.value == "[" ) {  
     // cout << "Rest_of_declarators-1 這裡要重新get" << endl;
     // 這裡要重新get
    GetNext( mnewtoken ) ;   
    mnewtoken = mScanner.PeekToken() ;
    if ( mnewtoken.type == CONSTANT ) {
      GetNext( token ) ;       
      index = token.value ;
      mnewtoken = mScanner.PeekToken() ;      
      if ( mnewtoken.value == "]" ) {
        GetNext( mnewtoken ) ;                   
      } // if 
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;
      } // else
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;
    } // else
  } // if  '[' Constant ']' 
  
  mnewtoken = mScanner.PeekToken() ;  
  while ( mnewtoken.value == "," ) {  
    // // cout << "Rest_of_declarators-2" << endl;
    Anslist temp_anslist ;    
    string f_name, f_index ;    
    
    GetNext( token ) ;    
    mnewtoken = mScanner.PeekToken() ; 
    if ( mnewtoken.type == STRING ) {
      GetNext( token ) ; 
      if ( token.value[0] == '\"' ) { 
        bool end = false ;
        string error_str ;
        for ( int i = 1 ; !end ; i++ )  {
          if ( token.value[i] == '\"' ) { 
            end = true ;
          } // if 
          else {
            error_str = error_str + token.value[i] ;
          } // else 
        } // for   
        
        token.value = error_str ;
        Errortype( token, errorMsg, error_f ) ;
        return false ;
      } // if             

      m_anscase = 1 ;
      temp_anslist.name = token.value ;  
      f_name = token.value ;  
      
     
      mnewtoken = mScanner.PeekToken() ;     
    
      if ( mnewtoken.value == "[" ) {  
         // cout << "Rest_of_declarators-1這裡要重新get" << endl;
        GetNext( mnewtoken ) ;   
        mnewtoken = mScanner.PeekToken() ;
        if ( mnewtoken.type == CONSTANT ) {
          GetNext( token ) ;  
          f_index = token.value ;     
          mnewtoken = mScanner.PeekToken() ;      
          if ( mnewtoken.value == "]" ) {
            GetNext( mnewtoken ) ;                   
          } // if 
          else {
            Errortype( mnewtoken, errorMsg, error_f ) ;
            return false ;
          } // else
        } // if 
        else {
          Errortype( mnewtoken, errorMsg, error_f ) ;
          return false ;
        } // else
      } // if  '[' Constant ']'
      
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;
    } // else
    
    Define_TID( f_name, m_anstype, f_index, levelnum ) ; 
    temp_anslist.anscase = m_anscase  ;   
    m_anslist.push_back( temp_anslist ) ;
    mnewtoken = mScanner.PeekToken() ;
    m_anscase = 1 ;
  } // while  { ',' Identifier [ '[' Constant ']' ] }
  
  if ( mnewtoken.value == ";" ) {    
    GetNext( mnewtoken ) ;
    // // cout << "Rest_of_declarators-3" << mnewtoken.value << endl;
    return true ;
  } // if 
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;
  } // else
  
                                       
} // Syntax::Rest_of_declarators()   

bool Syntax::Function_definition_without_ID( Token & token, Calculate & now_data,
                                             string & errorMsg, Token & now_token, int & levelnum ) {  
  // '(' [ VOID | formal_parameter_list ] ')' compound_statement
  // 第一個'('已經讀了 
  int beg_level = levelnum ;  
  levelnum++ ;
  string error_f = "Function_definition_without_ID" ;     
  mnewtoken = mScanner.PeekToken() ;  
  m_levelplus = false ;
  // // // cout << "Function_definition_without_ID  " << mnewtoken.value << endl ;   
  if ( mnewtoken.value == "void" ) {
    // 找已經宣告過的 function ??  
    // // // cout << "Function_definition_without_ID -1 void ????   " << endl ;
    GetNext( token ) ;
  } // if 
  else if ( Type_specifier( mnewtoken ) )  {
    // 這裡會需要加一層
    m_levelplus = true ;
    if ( !Formal_parameter_list( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;
    } // if        
    // // cout << "出來" << endl ; 
  } // else if 

  mnewtoken = mScanner.PeekToken() ;
  if ( mnewtoken.value == ")" ) { 
    GetNext( token ) ; 
    mnewtoken = mScanner.PeekToken() ;
    if ( mnewtoken.value == "{" ) { 
      GetNext( token ) ;  
      levelnum-- ;
      // 層數控制 下去會多加一次先剪掉 
      if ( Compound_statement( token, now_data, errorMsg, now_token, levelnum ) ) return true ;
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
          m_namelist.pop_back() ;
        levelnum-- ;        
        // cout << " levelnum-- ( 1 ) "<< levelnum << endl ;         
        return false ;
      } // else 
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
        m_namelist.pop_back() ;      
      levelnum-- ;
      // // cout << " levelnum-- ( 2 ) "<< levelnum << endl ;       
      return false ;
    } // else
  } // if 
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
      m_namelist.pop_back() ;    
    levelnum-- ;
    // cout << " levelnum-- ( 3 ) " << levelnum << endl ;     
    return false ;
  } // else  
     
} // Syntax::Function_definition_without_ID()  

bool Syntax::Formal_parameter_list( Token & token, Calculate & now_data,
                                    string & errorMsg, Token & now_token, int & levelnum ) {
  // type_specifier [ '&' ] Identifier [ '[' Constant ']' ] 
  // { ',' type_specifier [ '&' ] Identifier [ '[' Constant ']' ] }
  string error_f = "Formal_parameter_list" ;   
  bool find = false ;
  string f_type, f_name, f_index ;  
  // // cout << "Formal_parameter_list  " << token.value << endl ;  
  // cout << " Formal_parameter_list-m_name_index :"  << m_name_index << endl ;   
  mnewtoken = mScanner.PeekToken() ;
  while  ( Type_specifier( mnewtoken ) && !find )  { 
    GetNext( token ) ; 
    f_type = token.value ;
    mnewtoken = mScanner.PeekToken() ;
    if ( mnewtoken.value == "&" ) {  
    
      GetNext( token ) ; 
      
    } // if [ '&' ] 
    
    mnewtoken = mScanner.PeekToken() ;
    
    if ( mnewtoken.type != STRING ) {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;         
    } // if   Identifier
    
    GetNext( token ) ; 
    f_name = token.value ;    
    if ( token.value[0] == '\"' ) { 
      bool end = false ;
      string error_str ;
      for ( int i = 1 ; !end ; i++ )  {
        if ( token.value[i] == '\"' ) { 
          end = true ;
        } // if 
        else {
          error_str = error_str + token.value[i] ;
        } // else 
      } // for   
      
      token.value = error_str ;
      Errortype( token, errorMsg, error_f ) ;
      return false ;
    } // if       
    
    
    
    
    
    mnewtoken = mScanner.PeekToken() ;
    
    if ( mnewtoken.value == "[" ) {  
      // FUN不用管 
      GetNext( token ) ; 
      mnewtoken = mScanner.PeekToken() ;    
      if ( mnewtoken.type != CONSTANT ) {  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;         
      } // if 
      
      GetNext( token ) ;          
      f_index = token.value ;
      mnewtoken = mScanner.PeekToken() ; 
      if ( mnewtoken.value != "]"  ) {  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;         
      } // if      
      
      GetNext( token ) ; 
    } // if [ '[' Constant ']' ] 
    
    Define_TID( f_name, f_type, f_index, levelnum ) ; 
    
    mnewtoken = mScanner.PeekToken() ;
    if ( mnewtoken.value == "," ) {
      GetNext( token ) ; 
      mnewtoken = mScanner.PeekToken() ;
    } // if 
    else find = true ;
  } // while 
  
  return true ; 
                        
} // Syntax::Formal_parameter_list()   

bool Syntax::Compound_statement( Token & token, Calculate & now_data,
                                 string & errorMsg, Token & now_token, int & levelnum ) {
  // '{' { declaration | statement } '}'   
  // 第一個 { 已讀         
  levelnum++ ;
  Define_FID( m_f_name, m_f_type, levelnum ) ;
  string error_f = "Compound_statement" ;
  Debug1( now_data, error_f, token ) ;
  mnewtoken = mScanner.PeekToken() ;
  int firstsize = m_namelist.size() ;
  while ( mnewtoken.type == STRING || mnewtoken.type == SIGN || mnewtoken.type == CONSTANT  
          || mnewtoken.value == "++" || mnewtoken.value == "--" || mnewtoken.value == "("
          || Type_specifier( mnewtoken ) || mnewtoken.type == COMMAND 
          || mnewtoken.value == ";" ) {            
    GetNext( token ) ;            
    if ( Type_specifier( token ) ) {
      if ( !Declaration( token, now_data, errorMsg, now_token, levelnum ) ) {

        return false ;       
      } // if 
    } // if declaration
    else {  
      if ( !Statement( token, now_data, errorMsg, now_token, levelnum ) ) {       
        
        return false ;      
      } // if 
    } // else statement
       
    mnewtoken = mScanner.PeekToken() ;           
  } // while 
 
  if ( mnewtoken.value == "}" ) { 
    if ( m_namelist.size() > levelnum && m_namelist.size() > 1 ) 
      m_namelist.pop_back() ;      
      
    levelnum-- ;  
    GetNext( token ) ;  
    m_anscase = 4 ;
    return true ;
  } // if 
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;
  } // else 
                      
} // Syntax::Compound_statement()   

bool Syntax::Declaration( Token & token, Calculate & now_data, string & errorMsg,
                          Token & now_token, int & levelnum )  {
  // type_specifier Identifier rest_of_declarators            
  // 已經先讀了 
  string f_name, f_type ;
  string error_f = "Declaration" ;    
  Debug1( now_data, error_f, token ) ;  
  string index ;
  if ( Type_specifier( token ) ) {
    mnewtoken = mScanner.PeekToken() ;  
    if ( mnewtoken.type == STRING ) {      
      GetNext( token ) ;  
      if ( token.value[0] == '\"' ) { 
        bool end = false ;
        string error_str ;
        for ( int i = 1 ; !end ; i++ )  {
          if ( token.value[i] == '\"' ) { 
            end = true ;
          } // if 
          else {
            error_str = error_str + token.value[i] ;
          } // else 
        } // for   
        
        token.value = error_str ;
        Errortype( token, errorMsg, error_f ) ;
        return false ;
      } // if        
      
      f_name = token.value ;
      f_type =  token.value ;
      if ( Rest_of_declarators(  token, now_data, errorMsg, now_token, index, levelnum  ) ) {
        Define_TID( f_name, f_type, index, levelnum ) ; 
        // 要分類  
        return true ;  
      } // if 
      else return false ;
        
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;
    } // else    
    
  } // if  
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;
  } // else   
} // Syntax::Declaration()  

bool Syntax::Statement( Token & token, Calculate & now_data,
                        string & errorMsg, Token & now_token, int & levelnum ) {
  // ';'the null statement | expression ';'  /* expression here should not be empty */
  //  RETURN [ expression ] ';' | compound_statement | IF '(' expression ')' statement [ ELSE statement ]
  // | WHILE '(' expression ')' statement | DO statement WHILE '(' expression ')' ';'
  // 已經先讀了 所以進來的要在外面peektoken 
  string error_f = "Statement" ;  
  Debug1( now_data, error_f, token ) ;     
  if ( token.value == "cout" ) m_cout = true ;
  
  
  if ( token.value == ";" ) { 
    return true ;
  } // if ˙一開始近來就是; 
  else if ( ( token.type == STRING || token.type == SIGN || token.type == CONSTANT || 
              token.value == "++" || token.value == "--" || token.value == "(" )   && 
            token.value != "return" && token.value != "if" && token.value != "else"
            && token.value != "while" && token.value != "do" ) {
    if ( !Expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // if         

  } // else if expression ';'
  else if ( token.value == "return" ) {
    mnewtoken = mScanner.PeekToken() ;    
    GetNext( token ) ;      
    if ( token.value == ";" ) 
      return true ;
    else if ( !Expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // else if           
  } // else if  RETURN [ expression ] ';'
  else if ( token.value == "{" ) {
    if ( Compound_statement( token, now_data, errorMsg, now_token, levelnum ) ) 
      return true ;
    else return false ;
  } // else if compound_statement     
  else if ( token.value == "if" ) {
    mnewtoken = mScanner.PeekToken() ;   
    if ( mnewtoken.value == "(" ) {
      GetNext( token ) ;   
      mnewtoken = mScanner.PeekToken() ;
      GetNext( token ) ;
      if ( !Expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
          m_namelist.pop_back() ;        
        levelnum-- ;
        return false ;        
      } // if 
      
      mnewtoken = mScanner.PeekToken() ;   
      if ( mnewtoken.value != ")" ) {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
          m_namelist.pop_back() ;        
        levelnum-- ;
        return false ;            
      } // if 
      
      GetNext( token ) ;
      mnewtoken = mScanner.PeekToken() ;         
      GetNext( token ) ;      
      if ( !Statement( token, now_data, errorMsg, now_token, levelnum ) ) {  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
          m_namelist.pop_back() ;        
        levelnum-- ;
        return false ;        
      } // if   
      
      mnewtoken = mScanner.PeekToken() ;   
      if ( mnewtoken.value == "else" ) {
        GetNext( token ) ;
        mnewtoken = mScanner.PeekToken() ;         
        GetNext( token ) ;      
        if ( !Statement( token, now_data, errorMsg, now_token, levelnum ) ) {  
          Errortype( mnewtoken, errorMsg, error_f ) ;
          if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
            m_namelist.pop_back() ;          
          levelnum-- ;
          return false ;        
        } // if         
      
      } // if      

      return true ;
      
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;         
    } // else 
  
  } // else if IF '(' expression ')' statement [ ELSE statement ]
  else if ( token.value == "while" ) {
    mnewtoken = mScanner.PeekToken() ;   
    if ( mnewtoken.value == "(" ) {
      // levelnum++ ;
      GetNext( token ) ;   
      mnewtoken = mScanner.PeekToken() ;
      GetNext( token ) ;     
      if ( !Expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
          m_namelist.pop_back() ;        
        levelnum-- ;
        return false ;        
      } // if 
      
      mnewtoken = mScanner.PeekToken() ;   
      if ( mnewtoken.value != ")" ) {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
          m_namelist.pop_back() ;
        levelnum-- ;
        return false ;            
      } // if 
      
      GetNext( token ) ;
      mnewtoken = mScanner.PeekToken() ;         
      GetNext( token ) ;      
      if ( !Statement( token, now_data, errorMsg, now_token, levelnum ) ) {  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
          m_namelist.pop_back() ;        
        levelnum-- ;
        return false ;        
      } // if
      
      return true ;
      
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;         
    } // else       
    
  } // else if WHILE '(' expression ')' statement
  else if ( token.value == "do" ) {
    // levelnum++ ;
    mnewtoken = mScanner.PeekToken() ;   
    GetNext( token ) ;   
    if ( !Statement( token, now_data, errorMsg, now_token, levelnum ) ) {  
      if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
        m_namelist.pop_back() ;      
      levelnum-- ;    
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;        
    } // if
    
    mnewtoken = mScanner.PeekToken() ;   
    if ( mnewtoken.value != "while" ) {
      if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
        m_namelist.pop_back() ;      
      levelnum-- ;      
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;            
    } // if 

    GetNext( token ) ;   
    mnewtoken = mScanner.PeekToken() ;   
    if ( mnewtoken.value != "(" ) {
      if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
        m_namelist.pop_back() ;      
      levelnum-- ;      
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;            
    } // if      
    
    GetNext( token ) ;  
    mnewtoken = mScanner.PeekToken() ;   
    GetNext( token ) ;   
    if ( !Expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
        m_namelist.pop_back() ;      
      levelnum-- ;
      return false ;        
    } // if  
  
    mnewtoken = mScanner.PeekToken() ;   
    if ( mnewtoken.value != ")" ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      if ( m_namelist.size() > levelnum && m_namelist.size() > 1 )
        m_namelist.pop_back() ;      
      levelnum-- ;        
      return false ;            
    } // if  
    
    GetNext( token ) ;         
    
  } // else if DO statement WHILE '(' expression ')' ';'     
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;
  } // else 
  
  mnewtoken = mScanner.PeekToken() ;  
  if ( mnewtoken.value == ";" )  { 
    GetNext( mnewtoken ) ;  
    return true ;
  } // if 最後結束是 ;   
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;  
    return false ;
  } // else 
                                       
} // Syntax::Statement()   

bool Syntax::Expression( Token & token, Calculate & now_data,
                         string & errorMsg, Token & now_token, int & levelnum ) {
  // basic_expression { ',' basic_expression }
  // 已經先讀了 
  string error_f = "Expression" ;  
  Debug1( now_data, error_f, token ) ;       

  if ( !Basic_expression( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;                  
  } // if     

  mnewtoken = mScanner.PeekToken() ;  
  while ( mnewtoken.value == "," )  { 
    GetNext( mnewtoken ) ;      
    mnewtoken = mScanner.PeekToken() ;     
    if ( mnewtoken.type == STRING || mnewtoken.type == SIGN || mnewtoken.type == CONSTANT  
         || mnewtoken.value == "++" || mnewtoken.value == "--" || mnewtoken.value == "(" ) {
      GetNext( token ) ;       
      if ( !Basic_expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;                  
      } // if         
    } // if 
    else {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // else   


    mnewtoken = mScanner.PeekToken() ; 
  } // while 
  
  return true ;
  
  
} // Syntax::Expression()   

bool Syntax::Basic_expression( Token & token, Calculate & now_data,
                               string & errorMsg, Token & now_token, int & levelnum ) {
  // Identifier rest_of_Identifier_started_basic_exp | 
  // ( PP | MM ) Identifier rest_of_PPMM_Identifier_started_basic_exp
  // sign { sign } signed_unary_exp romce_and_romloe | ( Constant | '(' expression ')' ) romce_and_romloe
  // 先讀過進來 
  string error_f = "Basic_expression" ; 
  Debug1( now_data, error_f, token ) ;     
 
  if ( token.type == STRING ) {    
    if ( Find_TID( token, errorMsg, error_f, levelnum ) ||
         Find_FID( token, errorMsg, error_f, levelnum ) ) {
      if ( token.value[0] == '"' || token.value[0] == '\'' )
        now_token = token ;
        
      Get_data( token, now_data, 0 ) ;
      errorMsg = "" ;    
      if ( Rest_of_Identifier_started_basic_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
        return true ;  
      } // if 
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;
      } // else 
    } // if 
    else return false ;
  } // if 先判斷是否是DEF過的  
  else if ( token.value == "++" || token.value == "--" ) {
    string operate = token.value ;   
    mnewtoken = mScanner.PeekToken() ;
    if ( mnewtoken.type == STRING ) {
      GetNext( token ) ;
      Get_data( token, now_data, 0 ) ;



           
      if ( Find_TID( token, errorMsg, error_f, levelnum ) ) {
        if ( operate == "++" ) {
          // cout << "operate = ++ 1 " << endl ;
          // 後加 
          now_data.num++ ;
          InsertData( now_data.name, now_data, now_data.index_num ) ;
        } // if 
        else if ( operate == "--" ) {
          // cout << "operate = -- 1 " << endl ;
          now_data.num-- ;
          InsertData( now_data.name, now_data, now_data.index_num ) ;
        } // else if

        
        
        if ( Rest_of_PPMM_Identifier_started_basic_exp( token, now_data, errorMsg,
                                                        now_token, levelnum ) ) {    

                                                        
                                                    
          return true ;
        } // if 
        else {
          Errortype( mnewtoken, errorMsg, error_f ) ;
          return false ;      
        } // else  
          
      } // if 
      else return false ;    
    } // if 
  } // else if ( PP | MM ) Identifier rest_of_PPMM_Identifier_started_basic_exp
  else if ( token.type == SIGN ) {
    string opstr = token.value ;
    mnewtoken = mScanner.PeekToken() ; 
    int sign = 1, inverse = 0 ;
    if ( token.value == "-" ) {            
      sign = sign * ( -1 ) ;
    } // if 
    else if ( token.value == "!" ) {            
      inverse++ ;
    } // else if     
    
    while ( mnewtoken.type == SIGN ) {
      if ( mnewtoken.value == "-" ) {            
        sign = sign * ( -1 ) ;
      } // if 
      else if ( mnewtoken.value == "!" ) {            
        inverse++ ;
      } // else if       

      GetNext( mnewtoken ) ;  
      mnewtoken = mScanner.PeekToken() ; 
    } // while 


    

    if ( Signed_unary_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      if ( inverse > 0 ) { 
        for ( ; inverse > 0 ; inverse-- ) {
          if ( now_data.value == "false" )  
            now_data.value = "true" ;
          else if ( now_data.value == "true" ) 
            now_data.value = "false" ;                       
        } // for
        
      } // if 
      else {    
        now_data.num = now_data.num * sign ;
      } // else      
      
      if ( Romce_and_romloe( token, now_data, errorMsg, now_token, levelnum ) ) {

        
        return true ;
        
      } // if 
      else return false ;    
    } // if 
    else return false ;
  
  } // else if sign { sign } signed_unary_exp romce_and_romloe
  else if ( token.type == CONSTANT ) {
    now_token = token ;
    Get_data( token, now_data, 0 ) ;
    if ( Romce_and_romloe( token, now_data, errorMsg, now_token, levelnum ) ) {
      return true ;  
    } // if 
    else return false ;    
    
        
  } // else if ( Constant ) romce_and_romloe
  else if ( token.value == "(" ) {
    mnewtoken = mScanner.PeekToken() ;       
    GetNext( token ) ; 
    if ( Expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
      mnewtoken = mScanner.PeekToken() ;   
      if ( mnewtoken.value == ")" ) {
        GetNext( mnewtoken ) ;
        if ( Romce_and_romloe( token, now_data, errorMsg, now_token, levelnum ) ) {
          return true ;  
        } // if 
        else return false ;             
      } // if 
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;      
      } // else
    } // if
    else return false ;
       
  } // else if ( '(' expression ')' ) romce_and_romloe
  else {  
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;
  } // else 
  
  return false ; // 注意 多家的 
} // Syntax::Basic_expression()   

bool Syntax::Rest_of_Identifier_started_basic_exp( Token & token, Calculate & now_data,
                                                   string & errorMsg, Token & now_token, int & levelnum ) {
  // [ '[' expression ']' ] ( assignment_operator basic_expression |  [ PP | MM ] romce_and_romloe )
  // | '(' [ actual_parameter_list ] ')' romce_and_romloe
  string error_f = "Rest_of_Identifier_started_basic_exp" ;  
  Debug1( now_data, error_f, token ) ;  

  string idname = token.value ;
  Token first_token = token ;
  int first_index_num = 0 ;
  mnewtoken = mScanner.PeekToken() ; 
  if ( mnewtoken.value != "(" ) { 
    if ( !Find_TID( token, errorMsg, error_f, levelnum ) ) {
      return false ;
    } // if         
  } // if 
  
  if ( mnewtoken.value == "(" ) {  
    if ( !Find_FID( token, errorMsg, error_f, levelnum ) ) {
      return false ;
    } // if     

    GetNext( token ) ;
    mnewtoken = mScanner.PeekToken() ;       
    if ( mnewtoken.value == ")" ) {       
      GetNext( token ) ;
    } // if 
    else if ( mnewtoken.type == STRING || mnewtoken.type == SIGN || mnewtoken.type == CONSTANT  
              || mnewtoken.value == "++" || mnewtoken.value == "--" || mnewtoken.value == "(" ) {   
      if ( Actual_parameter_list( token, now_data, errorMsg, now_token, levelnum ) ) {  
        mnewtoken = mScanner.PeekToken() ;   
        if ( mnewtoken.value == ")" ) {
          GetNext( token ) ;
        } // if 
        else {
          return false ;             
        } // else
      } // if 
      else return false ;
    } // else if                                    

    if ( Romce_and_romloe( token, now_data, errorMsg, now_token, levelnum ) ) {         
      return true ;  
    } // if     
    else return false ;
    

    // else return false ;
  } // if 文法成功不會到下面   '(' [ actual_parameter_list ] ')' romce_and_romloe      
  else if ( mnewtoken.value == "[" ) {  

    GetNext( mnewtoken ) ; 
    mnewtoken = mScanner.PeekToken() ;
    GetNext( token ) ;
    Calculate temp_data2 = now_data ; 
    first_index_num = atoi( token.value.c_str() ) ;
    if ( !Expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // if    
    
    
    Get_data2( temp_data2, first_index_num ) ;
    now_data = temp_data2 ; 
    now_data.index_num =  first_index_num ; 
    mnewtoken = mScanner.PeekToken() ;
    if ( mnewtoken.value == "]" ) {  
      GetNext( token ) ;
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // else 
    
  } // else if 

  mnewtoken = mScanner.PeekToken() ;  
  if ( Assignment_operator( mnewtoken ) ) {  

    GetNext( token ) ;
    string operate = token.value ;
    mnewtoken = mScanner.PeekToken() ;
    GetNext( token ) ; 
    if ( Basic_expression( token, now_data, errorMsg, now_token, levelnum ) ) {
      //      cout << "ID#" << idname << endl ;
      //      cout << "Basic" << now_token.value << endl ;
      Calculate temp_data = now_data ;
      if ( operate == "=" ) {    
        InsertData( idname, now_data, first_index_num ) ;
      } // if 
      else if ( operate == "+=" ) {
        // Get_data2( now_data, first_index_num ) ;
        Get_data( first_token, now_data, first_index_num ) ;
        if ( now_data.num == -99999 && temp_data.num == -99999 ) {
          now_data.value = now_data.value + temp_data.value  ;
          now_data.num = -99999 ;
        } // if 
        else if ( temp_data.num == -99999 ) {
          now_data.value = temp_data.value + D_to_S( now_data.num ) ;
          now_data.num = -99999 ;        
        } // else if 
        else if ( now_data.num == -99999 ) {
          now_data.value = D_to_S( temp_data.num ) + now_data.value ;          
          now_data.num = -99999 ;        
        } // else if 
        else { 
          now_data.num = now_data.num + temp_data.num ;
        } // else                        

        InsertData( idname, now_data, first_index_num ) ;
      } // else if    
      else if ( operate == "-=" ) {
        Get_data( first_token, now_data, first_index_num ) ;
        now_data.num = now_data.num - temp_data.num ;
        InsertData( idname, now_data, first_index_num ) ;     
      } // else if  
      else if ( operate == "*=" ) {
        Get_data( first_token, now_data, first_index_num ) ;
        if ( now_data.type == "int" ||  temp_data.type == "int" )   
          now_data.num =  floor( now_data.num * temp_data.num ) ;
        else   
          now_data.num = now_data.num * temp_data.num ;              
        
      } // else if  
      else if ( operate == "/=" ) {
        Get_data( first_token, now_data, first_index_num ) ;
        // now_data.num = ceil( now_data.num / temp_data.num ) ;
        if ( now_data.type == "int" ||  temp_data.type == "int" ) { 
          if ( ( now_data.num / temp_data.num ) > 0 ) {
            now_data.num = ceil( now_data.num / temp_data.num ) ;
          } // if c eil
          else if ( ( now_data.num / temp_data.num ) < 0 ) {
            now_data.num = floor( now_data.num / temp_data.num ) ;   
          } // else if   
        } // if 
        else {
          now_data.num = now_data.num / temp_data.num ;
        } // else 
        
        InsertData( idname, now_data, first_index_num ) ;           
      } // else if  
      else if ( operate == "%=" ) {
        Get_data( first_token, now_data, first_index_num ) ;
        int a = now_data.num, b = temp_data.num ;
        now_data.num = a % b ;
        InsertData( idname, now_data, first_index_num ) ; 
      } // else if   
      
      return true ;    
    } // if 
    else {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // else      
  
  } // if   assignment_operator basic_expression 
  else if ( mnewtoken.value == "++" || mnewtoken.value == "--" ) {
    GetNext( token ) ;
    PP_MM temp_pm ;
    temp_pm.now_data = now_data ;
    temp_pm.operate = token.value ;
    m_pp_mm.push_back( temp_pm ) ;

    if ( Romce_and_romloe( token, now_data, errorMsg, now_token, levelnum ) ) return true ;    
    else {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // else 
      
  } // else if [ PP | MM ] romce_and_romloe
  else if ( Romce_and_romloe( token, now_data, errorMsg, now_token, levelnum ) ) return true ;
  else {  
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;                  
  } // else  
  
                          
} // Syntax::Rest_of_Identifier_started_basic_exp()   

bool Syntax::Rest_of_PPMM_Identifier_started_basic_exp( Token & token, Calculate & now_data,
                                                        string & errorMsg, Token & now_token,
                                                        int & levelnum ) {
  // [ '[' expression ']' ] romce_and_romloe    
  string error_f = "Rest_of_PPMM_Identifier_started_basic_exp" ; 
  Debug1( now_data, error_f, token ) ;   
  mnewtoken = mScanner.PeekToken() ;
  if ( mnewtoken.value == "[" ) { 
    GetNext( token ) ;
    mnewtoken = mScanner.PeekToken() ;
    GetNext( token ) ;      
    Calculate temp_data2 = now_data ;  
    int first_index_num = 0 ;
    first_index_num = atoi( token.value.c_str() ) ;    
    if ( Expression( token, now_data, errorMsg, now_token, levelnum ) ) {
      mnewtoken = mScanner.PeekToken() ;
      if ( mnewtoken.value == "]" ) {
        Get_data2( temp_data2, first_index_num ) ;
        now_data = temp_data2 ; 
        now_data.index_num =  first_index_num ;         
        
        GetNext( token ) ;
        return true ;
      } // if 
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;      
      } // else 
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // else         
    
  } // if 0-1次不用回傳false   
  
  if ( Romce_and_romloe( token, now_data, errorMsg, now_token, levelnum ) ) return true ;
  else return false ;     
    
  
  
} // Syntax::Rest_of_PPMM_Identifier_started_basic_exp() 
  
bool Syntax::Sign( Token & token, Calculate & now_data,
                   string & errorMsg, Token & now_token, int & levelnum ) {
  // '+' | '-' | '!'
  string error_f = "Sign" ;    
  if ( token.value == "+" || token.value == "-" || token.value == "!" ) return true ;
  else return false ;                                           
} // Syntax::Sign()  
   
bool Syntax::Actual_parameter_list( Token & token, Calculate & now_data,
                                    string & errorMsg, Token & now_token, int & levelnum ) {
  //  basic_expression { ',' basic_expression }
  // 沒有先讀   
  string error_f = "Actual_parameter_list" ;   
  Debug1( now_data, error_f, token ) ;   
  mnewtoken = mScanner.PeekToken() ;  
  if ( mnewtoken.type == STRING || mnewtoken.type == SIGN || mnewtoken.type == CONSTANT  
       || mnewtoken.value == "++" || mnewtoken.value == "--" || mnewtoken.value == "(" ) {
    GetNext( token ) ;      
    if ( !Basic_expression( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // if     
  } // if  
  else {  
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;                  
  } // else 
  
  mnewtoken = mScanner.PeekToken() ;  
  while ( mnewtoken.value == "," )  { 
    GetNext( mnewtoken ) ;      
    mnewtoken = mScanner.PeekToken() ;     
    if ( mnewtoken.type == STRING || mnewtoken.type == SIGN || mnewtoken.type == CONSTANT  
         || mnewtoken.value == "++" || mnewtoken.value == "--" || mnewtoken.value == "(" ) {
      GetNext( token ) ;       
      if ( !Basic_expression( token, now_data, errorMsg, now_token, levelnum ) ) {  
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;                  
      } // if         
    } // if 
    else {  
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;                  
    } // else   


    mnewtoken = mScanner.PeekToken() ; 
  } // while 
  
  return true ;
  
} // Syntax::Actual_parameter_list()   

bool Syntax::Assignment_operator( Token & token ) {
  // '=' | TE | DE | RE | PE | ME  
  if ( token.value == "=" || token.value == "*=" || token.value == "/="
       || token.value == "%=" || token.value == "-=" || token.value == "+=" ) return true ;
  else return false ;     
  
} // Syntax::Assignment_operator()  
 
bool Syntax::Romce_and_romloe( Token & token, Calculate & now_data,
                               string & errorMsg, Token & now_token, int & levelnum ) {
  //  rest_of_maybe_logical_OR_exp [ '?' basic_expression ':' basic_expression ] 
  string error_f = "Romce_and_romloe" ;    
  Debug1( now_data, error_f, token ) ;    
  if ( !Rest_of_maybe_logical_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if 
  
  mnewtoken = mScanner.PeekToken() ;
  if ( mnewtoken.value == "?" ) {
    GetNext( token ) ;
    mnewtoken = mScanner.PeekToken() ;
    GetNext( token ) ;
    if ( !Basic_expression( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;         
    } // if '?' basic_expression
    
    mnewtoken = mScanner.PeekToken() ;
    if ( mnewtoken.value == ":" ) {  
      GetNext( token ) ;
      mnewtoken = mScanner.PeekToken() ;
      GetNext( token ) ;
      if ( Basic_expression( token, now_data, errorMsg, now_token, levelnum ) ) return true ;
      else {        
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;         
      } // else         
    } // if ':' basic_expression
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;       
    } // else  
  
  } // if [ '?' basic_expression ':' basic_expression ]
  else {  
    return true ;            
  } // else 
} // Syntax::Romce_and_romloe()   

bool Syntax::Rest_of_maybe_logical_OR_exp( Token & token, Calculate & now_data,
                                           string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_logical_AND_exp { OR maybe_logical_AND_exp }
  string error_f = "Rest_of_maybe_logical_OR_exp" ;  
  Debug1( now_data, error_f, token ) ;    
  if ( !Rest_of_maybe_logical_AND_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "||" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;        
    GetNext( token ) ;
    if ( !Maybe_logical_AND_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    if ( operate == "||" ) {
      if ( temp_data.value == "true" || now_data.value == "true" ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
      
    } // if     
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
  
  return true ;            
  
} // Syntax::Rest_of_maybe_logical_OR_exp()   

bool Syntax::Maybe_logical_AND_exp( Token & token, Calculate & now_data,
                                    string & errorMsg, Token & now_token, int & levelnum ) {
  // maybe_bit_OR_exp { AND maybe_bit_OR_exp }     
  string error_f = "Maybe_logical_AND_exp" ;   
  Debug1( now_data, error_f, token ) ;       
  if ( !Maybe_bit_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "&&" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;     
    GetNext( token ) ;
    if ( !Maybe_bit_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    if ( operate == "&&" ) {
      if ( temp_data.value == "true" && now_data.value == "true" ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
      
    } // if        
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 

  return true ;   
  
} // Syntax::Maybe_logical_AND_exp()   

bool Syntax::Rest_of_maybe_logical_AND_exp( Token & token, Calculate & now_data,
                                            string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_bit_OR_exp { AND maybe_bit_OR_exp }
  string error_f = "Rest_of_maybe_logical_AND_exp" ; 
  Debug1( now_data, error_f, token ) ;          
  if ( !Rest_of_maybe_bit_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "&&" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;        
    GetNext( token ) ;
    if ( !Maybe_bit_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  

    if ( operate == "&&" ) {
      if ( temp_data.value == "true" && now_data.value == "true" ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else     
     
    } // if         
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
  
  return true ;  
  
} // Syntax::Rest_of_maybe_logical_AND_exp()   

bool Syntax::Maybe_bit_OR_exp( Token & token, Calculate & now_data,
                               string & errorMsg, Token & now_token, int & levelnum ) {
  // maybe_bit_ex_OR_exp { '|' maybe_bit_ex_OR_exp }
  string error_f = "Maybe_bit_OR_exp" ;   
  Debug1( now_data, error_f, token ) ;    
  if ( !Maybe_bit_ex_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "|" ) {
    GetNext( token ) ;
    if ( !Maybe_bit_ex_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
  
  
  return true ;    
  
} // Syntax::Maybe_bit_OR_exp()     

bool Syntax::Rest_of_maybe_bit_OR_exp( Token & token, Calculate & now_data,
                                       string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_bit_ex_OR_exp { '|' maybe_bit_ex_OR_exp }
  string error_f = "Rest_of_maybe_bit_OR_exp" ;  
  Debug1( now_data, error_f, token ) ;         
  
  if ( !Rest_of_maybe_bit_ex_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "|" ) {
    GetNext( token ) ;
    if ( !Maybe_bit_ex_OR_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 

  return true ;   
  
} // Syntax::Rest_of_maybe_bit_OR_exp()   

bool Syntax::Maybe_bit_ex_OR_exp( Token & token, Calculate & now_data,
                                  string & errorMsg, Token & now_token, int & levelnum ) {
  // maybe_bit_AND_exp { '^' maybe_bit_AND_exp }
  string error_f = "Maybe_bit_ex_OR_exp" ;   
  Debug1( now_data, error_f, token ) ;    
  if ( !Maybe_bit_AND_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "^" ) {
    GetNext( token ) ;
    if ( !Maybe_bit_AND_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
 
  return true ;   
  
} // Syntax::Maybe_bit_ex_OR_exp()  
 
bool Syntax::Rest_of_maybe_bit_ex_OR_exp( Token & token, Calculate & now_data,
                                          string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_bit_AND_exp { '^' maybe_bit_AND_exp }
  string error_f = "Rest_of_maybe_bit_ex_OR_exp" ;  
  Debug1( now_data, error_f, token ) ;            
  if ( !Rest_of_maybe_bit_AND_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "^" ) {
    GetNext( token ) ;
    if ( !Maybe_bit_AND_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
     
  return true ;    
  
} // Syntax::Rest_of_maybe_bit_ex_OR_exp()   

bool Syntax::Maybe_bit_AND_exp( Token & token, Calculate & now_data,
                                string & errorMsg, Token & now_token, int & levelnum ) {
  // maybe_equality_exp { '&' maybe_equality_exp }
  string error_f = "Maybe_bit_AND_exp" ;  
  Debug1( now_data, error_f, token ) ;    

  if ( !Maybe_equality_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "&" ) {
    GetNext( token ) ;
    if ( !Maybe_equality_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
      
  return true ;  
  
} // Syntax::Maybe_bit_AND_exp()   

bool Syntax::Rest_of_maybe_bit_AND_exp( Token & token, Calculate & now_data,
                                        string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_equality_exp { '&' maybe_equality_exp }
  string error_f = "Rest_of_maybe_bit_AND_exp" ;    
  Debug1( now_data, error_f, token ) ;    
 
  if ( !Rest_of_maybe_equality_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "&" ) {
    GetNext( token ) ;
    if ( !Maybe_equality_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
  
   
  return true ;  
  
} // Syntax::Rest_of_maybe_bit_AND_exp()   

bool Syntax::Maybe_equality_exp( Token & token, Calculate & now_data,
                                 string & errorMsg, Token & now_token, int & levelnum ) {
  //  maybe_relational_exp { ( EQ | NEQ ) maybe_relational_exp}
  string error_f = "Maybe_equality_exp" ;   
  Debug1( now_data, error_f, token ) ;    
      
  if ( !Maybe_relational_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "==" || mnewtoken.value == "!=" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;      
    GetNext( token ) ;
    if ( !Maybe_relational_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  

    if ( operate == "==" ) {
      if ( temp_data.num == now_data.num )  {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if  
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;       
      } // else 
    } // if 
    else if ( operate == "!=" ) {
      if ( temp_data.num != now_data.num )  {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if  
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;       
      } // else 

    } // else if
       
    mnewtoken = mScanner.PeekToken() ;
  } // while 
    
  return true ;
  
} // Syntax::Maybe_equality_exp()   

bool Syntax::Rest_of_maybe_equality_exp( Token & token, Calculate & now_data,
                                         string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_relational_exp { ( EQ | NEQ ) maybe_relational_exp }
  string error_f = "Rest_of_maybe_equality_exp" ;   
  Debug1( now_data, error_f, token ) ;     
   
  if ( !Rest_of_maybe_relational_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "==" || mnewtoken.value == "!=" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;      
    GetNext( token ) ;
    if ( !Maybe_relational_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if 

    if ( operate == "==" ) {
      if ( temp_data.num == now_data.num )  {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if  
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;       
      } // else 
    } // if 
    else if ( operate == "!=" ) {
      if ( temp_data.num != now_data.num )  {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if  
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;       
      } // else 

    } // else if     
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
 
  return true ;
} // Syntax::Rest_of_maybe_equality_exp()
 
bool Syntax::Maybe_relational_exp( Token & token, Calculate & now_data,
                                   string & errorMsg, Token & now_token, int & levelnum ) {
  // maybe_shift_exp  { ( '<' | '>' | LE | GE ) maybe_shift_exp }
  string error_f = "Maybe_relational_exp" ;   
  Debug1( now_data, error_f, token ) ;    
   
  if ( !Maybe_shift_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "<" || mnewtoken.value == ">" || mnewtoken.value == ">="
          || mnewtoken.value == "<=" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;                
    GetNext( token ) ;
    if ( !Maybe_shift_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    if ( operate == "<" ) {
      if ( temp_data.num < now_data.num ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
    } // if 
    else if ( operate == ">" ) {
      if ( temp_data.num > now_data.num ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
    } // else if   
    else if ( operate == ">=" ) {
      if ( temp_data.num >= now_data.num ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
    } // else if 
    else if ( operate == "<=" ) {
      if ( temp_data.num <= now_data.num ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
    } // else if     
    
    
        
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
   
  return true ;
} // Syntax::Maybe_relational_exp()  
 
bool Syntax::Rest_of_maybe_relational_exp( Token & token, Calculate & now_data,
                                           string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_shift_exp { ( '<' | '>' | LE | GE ) maybe_shift_exp }
  string error_f = "Rest_of_maybe_relational_exp" ;
  Debug1( now_data, error_f, token ) ;         
    
  if ( !Rest_of_maybe_shift_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "<" || mnewtoken.value == ">" || mnewtoken.value == ">="
          || mnewtoken.value == "<=" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;             
    GetNext( token ) ;
    if ( !Maybe_shift_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    if ( operate == "<" ) {
      if ( temp_data.num < now_data.num ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
    } // if 
    else if ( operate == ">" ) {
      if ( temp_data.num > now_data.num ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
    } // else if   
    else if ( operate == ">=" ) {
      if ( temp_data.num >= now_data.num ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
    } // else if 
    else if ( operate == "<=" ) {
      if ( temp_data.num <= now_data.num ) {
        now_data.num = -99999 ;
        now_data.value = "true" ;
      } // if 
      else {
        now_data.num = -99999 ;
        now_data.value = "false" ;            
      } // else      
    } // else if     
    
    
    
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
   
  return true ;
} // Syntax::Rest_of_maybe_relational_exp() 
  
bool Syntax::Maybe_shift_exp( Token & token, Calculate & now_data,
                              string & errorMsg, Token & now_token, int & levelnum ) {
  // maybe_additive_exp { ( LS | RS ) maybe_additive_exp }
  string error_f = "Maybe_shift_exp" ;  
  Debug1( now_data, error_f, token ) ;    
 
  if ( !Maybe_additive_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  
  
  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "<<" || mnewtoken.value == ">>" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;    
    GetNext( token ) ;
    if ( !Maybe_additive_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    if ( operate == "<<" && m_brackets > 0 ) {
      for ( int k = 0 ; k < now_data.num ; k++ ) {
        temp_data.num = temp_data.num * 2 ;
      } // for 

      now_data.num = floor( temp_data.num ) ;    
    } // if 
    else if ( operate == ">>" && m_brackets > 0 ) {
      for ( int k = 0 ; k < now_data.num ; k++ ) {
        temp_data.num = temp_data.num / 2 ;
      } // for 

      now_data.num = floor( temp_data.num ) ;  
    
    } // else if      
    else if ( operate == "<<" && m_brackets == 0 )
      New_Ans( now_data ) ;
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
  
  return true ;  
  
} // Syntax::Maybe_shift_exp()   

bool Syntax::Rest_of_maybe_shift_exp( Token & token, Calculate & now_data,
                                      string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_additive_exp { ( LS | RS ) maybe_additive_exp }
  string error_f = "Rest_of_maybe_shift_exp" ;    
  Debug1( now_data, error_f, token ) ;    


  if ( !Rest_of_maybe_additive_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  

  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "<<" || mnewtoken.value == ">>" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;
    GetNext( token ) ;
    if ( !Maybe_additive_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  
    
    if ( operate == "<<" && m_brackets > 0 ) {
      for ( int k = 0 ; k < now_data.num ; k++ ) {
        temp_data.num = temp_data.num * 2 ;
      } // for 

      now_data.num = floor( temp_data.num ) ;  
    } // if 
    else if ( operate == ">>" && m_brackets > 0 ) {

      for ( int k = 0 ; k < now_data.num ; k++ ) {
        temp_data.num = temp_data.num / 2 ;
      } // for 

      now_data.num = floor( temp_data.num ) ;   

    } // else if 
    else if ( operate == "<<" && m_brackets == 0 )
      New_Ans( now_data ) ;    
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
  
  return true ;    
  
} // Syntax::Rest_of_maybe_shift_exp()   

bool Syntax::Maybe_additive_exp( Token & token, Calculate & now_data,
                                 string & errorMsg, Token & now_token, int & levelnum ) {
  // maybe_mult_exp { ( '+' | '-' ) maybe_mult_exp }
  string error_f = "Maybe_additive_exp" ;
  Debug1( now_data, error_f, token ) ;       

  if ( !Maybe_mult_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  

  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "+" || mnewtoken.value == "-" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;      
    GetNext( token ) ;
    if ( !Maybe_mult_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  

    if ( operate == "+" ) {
      if ( now_data.num == -99999 && temp_data.num == -99999 ) {
        now_data.value = temp_data.value + now_data.value ;
        now_data.num = -99999 ;
      } // if 
      // else if ( temp_data.num == -99999 ) {
      //  now_data.value = temp_data.value + D_to_S( now_data.num ) ;
      //  now_data.num = -99999 ;        
      // } // else if 
      // else if ( now_data.num == -99999 ) {
      //   now_data.value = D_to_S( temp_data.num ) + now_data.value ;          
      //   now_data.num = -99999 ;        
      // } // else if 
      else {    
        now_data.num = temp_data.num + now_data.num ;
      } // else 
    } // if 
    else if ( operate == "-" ) {
      now_data.num = temp_data.num - now_data.num ;    
    } // else if     
    
    mnewtoken = mScanner.PeekToken() ;
  } // while 
 
  return true ;   
  
} // Syntax::Maybe_additive_exp()     

bool Syntax::Rest_of_maybe_additive_exp( Token & token, Calculate & now_data,
                                         string & errorMsg, Token & now_token, int & levelnum ) {
  // rest_of_maybe_mult_exp { ( '+' | '-' ) maybe_mult_exp }
  string error_f = "Rest_of_maybe_additive_exp" ;
  Debug1( now_data, error_f, token ) ;      
   
  if ( !Rest_of_maybe_mult_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // if  

  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "+" || mnewtoken.value == "-" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;  
    GetNext( token ) ;
    if ( !Maybe_mult_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  

    if ( operate == "+" ) {
      if ( now_data.num == -99999 && temp_data.num == -99999 ) {
        now_data.value = temp_data.value + now_data.value ;
        now_data.num = -99999 ;
      } // if 
      // else if ( temp_data.num == -99999 ) {
      //   now_data.value = temp_data.value + D_to_S( now_data.num ) ;
      //   now_data.num = -99999 ;        
      // } // else if 
      // else if ( now_data.num == -99999 ) {
      //   now_data.value = D_to_S( temp_data.num ) + now_data.value ;          
      //   now_data.num = -99999 ;        
      // } // else if 
      else { 
        now_data.num = temp_data.num + now_data.num ;
      } // else 
    } // if 
    else if ( operate == "-" ) {
      now_data.num = temp_data.num - now_data.num ;    
    } // else if 

    mnewtoken = mScanner.PeekToken() ;
  } // while 
   
  return true ;   
  
} // Syntax::Rest_of_maybe_additive_exp()   

bool Syntax::Maybe_mult_exp( Token & token, Calculate & now_data,
                             string & errorMsg, Token & now_token, int & levelnum ) {
  // unary_exp rest_of_maybe_mult_exp
  string error_f = "Maybe_mult_exp" ;  
  Debug1( now_data, error_f, token ) ;    
    
  if ( Unary_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    if ( Rest_of_maybe_mult_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      return true ;
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // else 
  } // if 
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // else  
} // Syntax::Maybe_mult_exp()     

bool Syntax::Rest_of_maybe_mult_exp( Token & token, Calculate & now_data,
                                     string & errorMsg, Token & now_token, int & levelnum ) {
  // { ( '*' | '/' | '%' ) unary_exp }  /* could be empty ! */
  string error_f = "Rest_of_maybe_mult_exp" ;  
  Debug1( now_data, error_f, token ) ;     

  mnewtoken = mScanner.PeekToken() ;
  while ( mnewtoken.value == "*" || mnewtoken.value == "/" || mnewtoken.value == "%" ) {
    Calculate temp_data = now_data ;
    string operate = mnewtoken.value ;    
    double temp1, temp2 ;    
    
    GetNext( token ) ;
    if ( !Unary_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // if  

    if ( operate == "*" ) {
      if ( now_data.type == "int" ||  temp_data.type == "int" ) {  
      
      //        if ( ( temp_data.num * now_data.num ) < 0 ) 
      //          now_data.num = floor( temp_data.num * now_data.num ) ;
      //        else if ( ( temp_data.num * now_data.num ) > 0 ) 
      //          now_data.num = ceil( temp_data.num * now_data.num ) ;     
       
          
        now_data.num = floor( temp_data.num * now_data.num ) ;
        now_data.inverse = temp_data.inverse ;

      } // if 
      else 
        now_data.num = temp_data.num * now_data.num ;      
    } // if 
    else if ( operate == "/" ) {
      if ( now_data.type == "int" ||  temp_data.type == "int" ) {  
        if ( ( temp_data.num / now_data.num ) > 0 ) {
          now_data.num = floor( temp_data.num / now_data.num ) ;
        } // if
        else if ( ( temp_data.num / now_data.num ) < 0 ) {
          now_data.num = ceil( temp_data.num / now_data.num ) ;   
        } // else if       
        //        if ( ( temp_data.num / now_data.num ) > 0 && temp_data.inverse == false ) {
        //          now_data.num = floor( temp_data.num / now_data.num ) ;
        //        } // if
        //        else if ( ( temp_data.num / now_data.num ) < 0 && temp_data.inverse == false ) {
        //          now_data.num = ceil( temp_data.num / now_data.num ) ;   
        //        } // else if      
        //        else if ( ( temp_data.num / now_data.num ) > 0 && temp_data.inverse == true ) {
        //          now_data.num = ceil( temp_data.num / now_data.num ) ;
        //        } // else if          
        //        else if ( ( temp_data.num / now_data.num ) < 0 && temp_data.inverse == true ) {  
        //          now_data.num = floor( temp_data.num / now_data.num ) ;        
        //        } // else if 

      } // if 
      else 
        now_data.num = temp_data.num / now_data.num ;          
    } // else if  
    else if ( operate == "%" ) {
      int a = temp_data.num, b = now_data.num ;
      now_data.num = a % b ;   
  
    } // else if  
    
    
    mnewtoken = mScanner.PeekToken() ;
  } // while   

  return true ; 
  
} // Syntax::Rest_of_maybe_mult_exp()   

bool Syntax::Unary_exp( Token & token, Calculate & now_data,
                        string & errorMsg, Token & now_token, int & levelnum ) {
// sign { sign } signed_unary_exp | unsigned_unary_exp | ( PP | MM ) Identifier [ '[' expression ']' ]
  string error_f = "Unary_exp" ;  
  Debug1( now_data, error_f, token ) ;    
   
  mnewtoken = mScanner.PeekToken() ;  
  if ( mnewtoken.type == SIGN ) {
    GetNext( token ) ;
    int sign = 1, inverse = 0 ; 
    if ( token.value == "-" ) {            
      sign = sign * ( -1 ) ;
    } // if    
    else if ( token.value == "!" ) {            
      inverse++ ;
    } // else if     
    
    mnewtoken = mScanner.PeekToken() ; 
    while ( mnewtoken.type == SIGN ) {
      if ( mnewtoken.value == "-" ) {            
        sign = sign * ( -1 ) ;
      } // if   
      else if ( mnewtoken.value == "!" ) {            
        inverse++  ;
      } // else if         

      GetNext( token ) ;
      mnewtoken = mScanner.PeekToken() ;     
    } // while 
    
    if ( Signed_unary_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
      if ( inverse > 0 ) {
        for ( ; inverse > 0 ; inverse-- ) {
          if ( now_data.value == "false" )  
            now_data.value = "true" ;
          else if ( now_data.value == "true" ) 
            now_data.value = "false" ;                       
        } // for
          
      } // if 
      else { 
        if ( sign == -1 ) {    
          now_data.inverse = true ;
        } // if 

        now_data.num = now_data.num * sign ;
      } // else  
      
      return true ; 
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;    
    } // else 
  
  } // if  sign { sign } signed_unary_exp
  else if ( mnewtoken.value == "++" || mnewtoken.value == "--" ) {        
    GetNext( token ) ;
    string operate = token.value ; 
    mnewtoken = mScanner.PeekToken() ;
    if ( mnewtoken.type == STRING ) {
      GetNext( token ) ;
      if ( Find_TID( token, errorMsg, error_f, levelnum ) ) {
        Get_data( token, now_data, 0 ) ;        
       
        
        mnewtoken = mScanner.PeekToken() ;
        if ( mnewtoken.value == "[" ) {  
          GetNext( token ) ;
          mnewtoken = mScanner.PeekToken() ;
          GetNext( token ) ;      
          Calculate temp_data2 = now_data ;
          int first_index_num = 0 ;          
          first_index_num = atoi( token.value.c_str() ) ;          
          if ( Expression( token, now_data, errorMsg, now_token, levelnum ) ) {
            mnewtoken = mScanner.PeekToken() ;
            if ( mnewtoken.value == "]" ) {


              Get_data2( temp_data2, first_index_num ) ;
              now_data = temp_data2 ; 
              now_data.index_num =  first_index_num ;               
              GetNext( token ) ;
              return true ;
            } // if 
            else {
              Errortype( mnewtoken, errorMsg, error_f ) ;
              return false ;      
            } // else 
            
            
            
            
          } // if 
          else {
            Errortype( mnewtoken, errorMsg, error_f ) ;
            return false ;      
          } // else         
          
        } // if 0-1次不用回傳false 
        
        if ( operate == "++" ) {
          // cout << "operate = ++ 2 " << endl ;
          // 後加 
          now_data.num++ ;
          InsertData( now_data.name, now_data, now_data.index_num ) ;
        } // if 
        else if ( operate == "--" ) {
          // cout << "operate = -- 2 " << endl ;
          now_data.num-- ;
          InsertData( now_data.name, now_data, now_data.index_num ) ;
        } // else if          
        
        
        return true ; 
        
      } // if 
      else return false ;
    } // if 先判斷是否是DEF過的     
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // else 
    
  } // else if   ( PP | MM ) Identifier [ '[' expression ']' ]
  else if ( Unsigned_unary_exp( token, now_data, errorMsg, now_token, levelnum ) ) {
    return true ;
  } // else if  unsigned_unary_exp


  Errortype( mnewtoken, errorMsg, error_f ) ;
  return false ;
  
  
  
                                       
} // Syntax::Unary_exp()     

bool Syntax::Signed_unary_exp( Token & token, Calculate & now_data, 
                               string & errorMsg, Token & now_token, int & levelnum ) {
// Identifier [ '(' [ actual_parameter_list ] ')' | '[' expression ']' ] 
// | Constant  | '(' expression ')'
  string error_f = "Signed_unary_exp" ;  
  Debug1( now_data, error_f, token ) ;    
  mnewtoken = mScanner.PeekToken() ;     
  if ( mnewtoken.type == STRING ) {
 
    GetNext( token ) ;
    if ( Find_TID( token, errorMsg, error_f, levelnum ) ||
         Find_FID( token, errorMsg, error_f, levelnum ) ) {
      errorMsg = "" ;
      mnewtoken = mScanner.PeekToken() ;
      if ( mnewtoken.value != "(" ) { 
        if ( !Find_TID( token, errorMsg, error_f, levelnum ) ) {
          return false ;
        } // if         

        Get_data( token, now_data, 0 ) ;
      } // if       
      
      
      if ( mnewtoken.value == "(" ) { 
        if ( !Find_FID( token, errorMsg, error_f, levelnum ) ) {
          return false ;
        } // if 
        
        GetNext( token ) ;    
        mnewtoken = mScanner.PeekToken() ;  
        if ( mnewtoken.value == ")" ) { 
          GetNext( token ) ;
          return true ;
        } // if 
        
        // GetNext( token ) ;
        mnewtoken = mScanner.PeekToken() ; 
        if ( mnewtoken.type == STRING || mnewtoken.type == SIGN || mnewtoken.type == CONSTANT  
             || mnewtoken.value == "++" || mnewtoken.value == "--" 
             || mnewtoken.value == "(" ) {                
          if ( !Actual_parameter_list( token, now_data, errorMsg, now_token, levelnum ) ) {
            Errortype( mnewtoken, errorMsg, error_f ) ;
            return false ;  
          } // if   
        } // if 
        
        mnewtoken = mScanner.PeekToken() ; 
        if ( mnewtoken.value == ")" ) { 
          GetNext( token ) ;
          return true ;
        } // if 
        else {
          Errortype( mnewtoken, errorMsg, error_f ) ;
          return false ;  
        } // else 
      } // if '(' [ actual_parameter_list ] ')'
      else if ( mnewtoken.value == "[" ) {
        GetNext( token ) ;
        mnewtoken = mScanner.PeekToken() ;
        GetNext( token ) ;
        Calculate temp_data2 = now_data ;
        int first_index_num = 0 ;        
        first_index_num = atoi( token.value.c_str() ) ;        
        if ( Expression( token, now_data, errorMsg, now_token, levelnum ) ) { 
          mnewtoken = mScanner.PeekToken() ;
          if ( mnewtoken.value == "]" ) {

            Get_data2( temp_data2, first_index_num ) ;
            now_data = temp_data2 ; 
            now_data.index_num =  first_index_num ;              
            GetNext( token ) ;
            return true ;
          } // if 
          else {
            Errortype( mnewtoken, errorMsg, error_f ) ;
            return false ;      
          } // else         
        } // if      
        else {
          Errortype( mnewtoken, errorMsg, error_f ) ;
          return false ;      
        } // else 
      } // else if   '[' expression ']'
      else return true ;
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // else     
  } // if 
  else if ( mnewtoken.type == CONSTANT ) {    
    GetNext( token ) ;
    Get_data( token, now_data, 0 ) ;
    now_token = token ;
    return true; 
  } // else if 
  else if ( mnewtoken.value == "("  ) {
    m_brackets++;
    GetNext( token ) ;
    mnewtoken = mScanner.PeekToken() ;
    GetNext( token ) ;
    if ( Expression( token, now_data, errorMsg, now_token, levelnum ) ) { 
      mnewtoken = mScanner.PeekToken() ;
      if ( mnewtoken.value == ")"  ) {
        m_brackets--;
        GetNext( token ) ;
        return true ;
      } // if 
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;      
      } // else         
    } // if      
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // else 
  } // else if  '(' expression ')'
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // else                                        
} // Syntax::Signed_unary_exp()   

bool Syntax::Unsigned_unary_exp( Token & token, Calculate & now_data,
                                 string & errorMsg, Token & now_token, int & levelnum ) {
// Identifier [ '(' [ actual_parameter_list ] ')' | [ '[' expression ']' ] [ ( PP | MM ) ] ]
// | Constant | '(' expression ')'
  string error_f = "Unsigned_unary_exp" ; 
  Debug1( now_data, error_f, token ) ;    
  mnewtoken = mScanner.PeekToken() ;

  
  if ( mnewtoken.type == STRING ) {
    GetNext( token ) ;
    if ( Find_TID( token, errorMsg, error_f, levelnum ) ||
         Find_FID( token, errorMsg, error_f, levelnum ) ) {
      errorMsg = "" ;
      mnewtoken = mScanner.PeekToken() ;
      if ( mnewtoken.value != "(" ) { 
        if ( !Find_TID( token, errorMsg, error_f, levelnum ) ) {
          return false ;
        } // if         

        Get_data( token, now_data, 0 ) ;

      } // if         
      
      
      if ( mnewtoken.value == "(" ) { 
        if ( !Find_FID( token, errorMsg, error_f, levelnum ) ) {
          return false ;
        } // if 
        
        GetNext( token ) ;    
        mnewtoken = mScanner.PeekToken() ;  
        if ( mnewtoken.value == ")" ) { 
          GetNext( token ) ;
          return true ;
        } // if 
        
        mnewtoken = mScanner.PeekToken() ; 
        if ( mnewtoken.type == STRING || mnewtoken.type == SIGN || mnewtoken.type == CONSTANT  
             || mnewtoken.value == "++" || mnewtoken.value == "--" 
             || mnewtoken.value == "(" ) {                
          if ( !Actual_parameter_list( token, now_data, errorMsg, now_token, levelnum ) ) {
            Errortype( mnewtoken, errorMsg, error_f ) ;
            return false ;  
          } // if   
        } // if 

        mnewtoken = mScanner.PeekToken() ; 
        if ( mnewtoken.value == ")" ) { 
          GetNext( token ) ;
          return true ;
        } // if 
        else {
          Errortype( mnewtoken, errorMsg, error_f ) ;
          return false ;  
        } // else 
      } // if '(' [ actual_parameter_list ] ')'
      else if ( mnewtoken.value == "[" ) {

        GetNext( token ) ;
        mnewtoken = mScanner.PeekToken() ;
        GetNext( token ) ;

        Calculate temp_data2 = now_data ;
        int first_index_num = 0 ;        
        first_index_num = atoi( token.value.c_str() ) ;        
        if ( Expression( token, now_data, errorMsg, now_token, levelnum ) ) { 
          mnewtoken = mScanner.PeekToken() ;
          if ( mnewtoken.value == "]" ) {
            GetNext( token ) ;
            
            Get_data2( temp_data2, first_index_num ) ;
            now_data = temp_data2 ; 
            now_data.index_num =  first_index_num ;  
            
            mnewtoken = mScanner.PeekToken() ;
            if ( mnewtoken.value == "++" || mnewtoken.value == "--" ) {      
              GetNext( token ) ;  
              PP_MM temp_pm ;
              temp_pm.now_data = now_data ;
              temp_pm.operate = token.value ;
              m_pp_mm.push_back( temp_pm ) ;                                              
            } // if 
        
            return true ;
          } // if 
          else {
            Errortype( mnewtoken, errorMsg, error_f ) ;
            return false ;      
          } // else         
        } // if      
        else {
          Errortype( mnewtoken, errorMsg, error_f ) ;
          return false ;      
        } // else 
      } // else if   '[' expression ']'
      else if ( mnewtoken.value == "++" || mnewtoken.value == "--" ) {
        GetNext( token ) ;
        PP_MM temp_pm ;
        temp_pm.now_data = now_data ;
        temp_pm.operate = token.value ;
        m_pp_mm.push_back( temp_pm ) ;                     

        return true ;
      } // else if 
      else return true ;
    } // if 
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // else     
  } // if 
  else if ( mnewtoken.type == CONSTANT ) {
    GetNext( token ) ;
    Get_data( token, now_data, 0 ) ;
    return true; 
  } // else if 
  else if ( mnewtoken.value == "("  ) {
    m_brackets++;
    GetNext( token ) ;
    mnewtoken = mScanner.PeekToken() ;
    GetNext( token ) ;
    if ( Expression( token, now_data, errorMsg, now_token, levelnum ) ) { 
      mnewtoken = mScanner.PeekToken() ;
      if ( mnewtoken.value == ")"  ) {
        m_brackets-- ;
        GetNext( token ) ;
        return true ;
      } // if 
      else {
        Errortype( mnewtoken, errorMsg, error_f ) ;
        return false ;      
      } // else         
    } // if      
    else {
      Errortype( mnewtoken, errorMsg, error_f ) ;
      return false ;      
    } // else 
  } // else if  '(' expression ')'
  else {
    Errortype( mnewtoken, errorMsg, error_f ) ;
    return false ;      
  } // else   
  
} // Syntax::Unsigned_unary_exp()      



















void Syntax::ListAllVariables() { 
  cout << "> " ;  
  vector<string> temp1 ;
  if ( m_namelist.size() > 0 ) { 
    for ( int i = 0 ; i <  m_namelist[0].token_id.size() ; i++ ) {
      temp1.push_back( m_namelist[0].token_id[i].name ) ;
    } // for 
    
    for ( int i = 0 ; i < m_namelist[0].token_id.size() ; i++ ) {
      for ( int j = 0; j < i ; j++ ) {
        if ( temp1[j] > temp1[i] ) {
          string temp2 = temp1[j] ;
          temp1[j] = temp1[i];
          temp1[i] = temp2;
        } // if  
      } // for 
    } // for 
    
    for ( int i = 0 ; i <  temp1.size() ; i++ ) {
      cout << temp1[i] << endl ; 
    } // for     
    
    
  } // if 

  
  
  
} // Syntax::ListAllVariables()

void Syntax::ListAllFunctions() { 
  cout << "> " ;  
  vector<string> temp1 ;
  if ( m_namelist.size() > 0 ) { 
    for ( int i = 0 ; i <  m_namelist[0].function_id.size() ; i++ ) {
      temp1.push_back( m_namelist[0].function_id[i].name ) ;
    } // for 
    
    for ( int i = 0 ; i < m_namelist[0].function_id.size() ; i++ ) {
      for ( int j = 0; j < i ; j++ ) {
        if ( temp1[j] > temp1[i] ) {
          string temp2 = temp1[j] ;
          temp1[j] = temp1[i];
          temp1[i] = temp2;
        } // if  
      } // for 
    } // for 
    
    for ( int i = 0 ; i <  temp1.size() ; i++ ) {
      cout << temp1[i] << "()" << endl ; 
    } // for     
    
    
  } // if 
  
} // Syntax::ListAllFunctions()

void Syntax::ListVariable( string name ) { 
  cout << "> " ;  
  string findname ;
  if ( name[0] == '\"' ) {  
    for ( int i = 1 ; i < name.length()-1 ; i++ )
      findname = findname + name[i] ;
      
    if ( m_namelist.size() > 0 ) {
      bool find = false ;       
      for ( int i = 0 ; i <  m_namelist[0].token_id.size() && !find ; i++ ) {
        if ( m_namelist[0].token_id[i].name == findname ) {   
          cout << m_namelist[0].token_id[i].type << " " ;
          cout << m_namelist[0].token_id[i].name ;
          if ( m_namelist[0].token_id[i].index != "\0" )
            cout << "[ " << m_namelist[0].token_id[i].index << " ] ;" << endl ;
          else cout << " ;" << endl ;
          find = true ; 
        } // if 
      } // for 
    } // if 
    
  } // if     
} // Syntax::ListVariable()

void Syntax::ListFunction( string name ) { 
  cout << "> " ;  
  string findname ;
  if ( name[0] == '\"' ) {  
    for ( int i = 1 ; i < name.length()-1 ; i++ )
      findname = findname + name[i] ;
      
    if ( m_namelist.size() > 0 ) {
      bool find = false ;       
      int white = 0 ;
      for ( int i = 0 ; i <  m_namelist[0].function_id.size() && !find ; i++ ) {
        if ( m_namelist[0].function_id[i].name == findname ) {   
          for ( int j = 0 ; j < m_namelist[0].function_id[i].index.size() ; j++ ) { 
      
            if  ( m_namelist[0].function_id[i].index[j] == "}" ) {
              white = white - 2 ;
              if ( j+1 < m_namelist[0].function_id[i].index.size() ) {              
                if ( m_namelist[0].function_id[i].index[j-1] != "}" && 
                     m_namelist[0].function_id[i].index[j+1] != "}" &&
                     m_namelist[0].function_id[i].index[j-1] != ";" )
                  cout << endl ;
              
              } // if 
              
              for ( int k = 0 ; k < white ; k++ )
                cout << " " ;
                
                
                
              cout << m_namelist[0].function_id[i].index[j] ;
              if ( j+1 < m_namelist[0].function_id[i].index.size() ) {    
                cout << endl ;
                if  ( m_namelist[0].function_id[i].index[j+1] != "}" ) {
                  for ( int k = 0 ; k < white ; k++ )
                    cout << " " ;                                
                } // if 
              } // if 
              
              
            } // if        
            else {
              cout << m_namelist[0].function_id[i].index[j] ; 
              bool next = false  ;
              if ( m_namelist[0].function_id[i].index[j] == "{" ) {             
                cout << endl ;
                white = white + 2 ;
                next = true ;
              } // if 
              else if  ( m_namelist[0].function_id[i].index[j] == ";" ) {
                cout << endl ;
                next = true ;                
              } // else if 
              
              if ( j+1 < m_namelist[0].function_id[i].index.size() && next ) {
                if ( m_namelist[0].function_id[i].index[j+1] != "}" ) {
                  for ( int k = 0 ; k < white ; k++ )
                    cout << " " ;
                } // if 
                
              } // if                                      
          
            } // else 
    
    
            if ( j+1 < m_namelist[0].function_id[i].index.size() ) {  
              if ( ( m_namelist[0].function_id[i].index[j] == "if" || 
                     m_namelist[0].function_id[i].index[j] == "while" || 
                     ( m_namelist[0].function_id[i].index[j+1] != "[" && 
                       m_namelist[0].function_id[i].index[j+1] != "(" ) ) && 
                   ( m_namelist[0].function_id[i].index[j+1] != "," &&
                     m_namelist[0].function_id[i].index[j+1] != "++" &&
                     m_namelist[0].function_id[i].index[j+1] != "--" &&
                     m_namelist[0].function_id[i].index[j] != ";" &&
                     m_namelist[0].function_id[i].index[j] != "}" &&
                     m_namelist[0].function_id[i].index[j] != "{" ) )          
                cout << " " ;
            } // if 
            

          } // for 
          
          cout << endl ;
        } // if 
      } // for
    
      
    } // if 
    
  } // if     
} // Syntax::ListFunction()  

void Syntax::Reset() {
  m_name_index = 0 ;  
  m_brackets = 0 ;
  m_anscase = -1 ;
  m_function_index.clear() ;
  m_ans_data.clear() ;
  m_pp_mm.clear() ;
  mScanner.Reset() ;
} // Syntax::Reset()

void Syntax::Reset2() {
  m_name_index = 0 ;  
  m_brackets = 0 ;
  m_anscase = -1 ;  
  m_ans_data.clear() ;
  m_function_index.clear() ;  
  m_pp_mm.clear() ;
  mScanner.Reset2() ;
} // Syntax::Reset2()









  // ------------------------------------------- Scanner -------------------------------------------
  
Token Scanner::PeekToken() {
  if ( mCur_token.value == "" )
    mCur_token = GetToken() ;
  return mCur_token ;
} // Scanner::PeekToken() 

Token Scanner:: GetToken() {
  Token temp_token ;  
  Type tokentype ; // 新token的類別  
  char temp_char ;  
  char new_char ;  
  temp_char = cin.peek() ;  
  
  
  if ( mCur_token.value != "" ) {
    temp_token.value = mCur_token.value ;
    temp_token.type = mCur_token.type ;
    temp_token.line = mLine ;
    temp_token.column = mColumn ;
    mCur_token.value = "" ;
    mCur_token.type = FIRST ;             
  } // if  
  
  else {
    if ( temp_char == ' ' || temp_char == '\t' ) {
      cin.get() ;
      mColumn++ ;
      temp_token = GetToken( ) ;
    } // if
    else if ( temp_char == '\n' ) {
      cin.get() ;
      mLine++ ;
      mColumn = 0 ;
      temp_token = GetToken() ;
    } // else if 
    else if ( temp_char == ';' ) {
      temp_char = cin.get() ;
      temp_token.type = PERIOD ;      
      temp_token.value = temp_token.value + temp_char ;           
      temp_char = cin.peek() ;
    } // else if 
    else if ( temp_char == '/' ) {    
      new_char = cin.get() ;
      mColumn++ ;
      temp_token.value = temp_token.value + temp_char ;
      temp_char = cin.peek() ;  
      if ( temp_char == '/' ) {
      // 判斷 //註解      
        while ( temp_char != '\n' ) {
          new_char = cin.get() ;
          mColumn++ ;
          temp_token.value = temp_token.value + temp_char ;
          temp_token.type = IGNORE ;    
          temp_char = cin.peek() ;                 
        } // while     
            
        temp_token = GetToken( ) ; // 再次呼叫 
      } // if 
      else if ( temp_char == '*' ) {
      // 判斷 /*註解 
        temp_token.type = IGNORE ;    
        new_char = cin.get() ;
        temp_token.value = temp_token.value + temp_char ; 
        bool end = false ;
        while ( !end )  {
          temp_char = cin.peek() ;
          if ( temp_char == '*' ) {
            new_char = cin.get() ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;          
            temp_char = cin.peek() ;          
            if ( temp_char == '/' ) {
              new_char = cin.get() ;
              mColumn++ ;
              temp_token.value = temp_token.value + temp_char ;                  
              temp_token = GetToken( ) ;  
              end = true ;         
            } // if 
          } // if 
          else if ( temp_char == '\n' ) {
            cin.get() ;
            mLine++ ;
            temp_token.value = temp_token.value + temp_char ;          
            mColumn = 0 ;    
          } // else if
          else {    
            new_char = cin.get() ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;            
          } // else         
        } // while           
        
      } // else if 
      else if ( temp_char == '=' ) {
        new_char = cin.get() ;
        mColumn++ ;        
        temp_token.value = temp_token.value + temp_char ; 
        temp_token.type = SYMBOL ;         
      } // else if 
      else temp_token.type = SYMBOL ;    
    } // else if    
    else if ( temp_char == '(' ) { 
      new_char = cin.get() ;
      mColumn++ ;
      temp_token.value = temp_token.value + temp_char ;
      temp_token.type = LP ;    
      // LEFT-PAREN
    } // else if
    else if ( temp_char == ')' ) {
      new_char = cin.get() ;
      mColumn++ ;
      temp_token.value = temp_token.value + temp_char ;
      temp_token.type = RP ;            
    // RIGHT-PAREN
    } // else if
    else if ( temp_char == ':' ) {
      new_char = cin.get() ;
      mColumn++ ;
      temp_token.value = temp_token.value + temp_char ;
      temp_char = cin.peek() ;  
      if ( temp_char == '=' ) {
        new_char = cin.get() ;
        mColumn++ ;
        temp_token.value = temp_token.value + temp_char ;
        temp_token.type = DEF ;    
        temp_char = cin.peek() ;                 
      } // if     
      else  temp_token.type = UNDEF ; 
      // DEF
    } // else if
    else if ( temp_char == '\'' ) {
      temp_char = cin.get() ;
      mColumn++ ;
      temp_token.value = temp_token.value + temp_char ;
      temp_token.type = STRING ;
      bool end = false ;
      while ( !end )  {
        temp_char = cin.peek() ;
        if ( temp_char == '\'' ) {
          new_char = cin.get() ;
          mColumn++ ;
          temp_token.value = temp_token.value + temp_char ;          
          end = true ;          
        } // if 第2個 " 結束 
        else if ( temp_char == '\n' ) {
          cin.get() ;
          // mLine++ ;
          temp_token.value = temp_token.value + temp_char ;          
          end = true ;
        } // else if
        else {    
          new_char = cin.get() ;
          mColumn++ ;
          temp_token.value = temp_token.value + temp_char ;            
        } // else         
      } // while  
    } // else if 
    // else if ( temp_char == '\"' ) {  
    //  temp_char = cin.get() ;
    //  mColumn++ ;
    //  temp_token.value = temp_token.value + temp_char ;
    //  temp_token.type = QUOTE ;
    // QUOTE
    // } // else if     
    else if ( temp_char == '\"' ) {  
      temp_char = cin.get() ;
      mColumn++ ;
      temp_token.value = temp_token.value + temp_char ;
      temp_token.type = STRING ;
      bool end = false ;
      while ( !end )  {
        temp_char = cin.peek() ;
        if ( temp_char == '\"' ) {
          new_char = cin.get() ;
          mColumn++ ;
          temp_token.value = temp_token.value + temp_char ;          
          end = true ;          
        } // if 第2個 " 結束 
        else if ( temp_char == '\n' ) {
          cin.get() ;
          temp_token.value = temp_token.value + temp_char ;          
          end = true ;  
        } // else if
        else {    
          new_char = cin.get() ;
          mColumn++ ;
          temp_token.value = temp_token.value + temp_char ;            
        } // else         
      } // while                 
      
    } // else if     
    
    else if ( CharIsUndef( temp_char ) ) {
      temp_char = cin.get() ;
      mColumn++ ;
      temp_token.value = temp_token.value + temp_char ;
      temp_token.type = UNDEF ;
      // UNDEF        
    } // else if 
    else {
      bool find = false ;
      Type last_type = FIRST ;
      while ( !find && temp_char != ' ' && temp_char != '\t' && temp_char != '\'' && temp_char != '\n'
              && temp_char != '(' && temp_char != ')' && temp_char != '\"' && temp_char != ';' ) {
        if ( last_type == FIRST ) {        
          if ( CharIsDigit( temp_char ) )  {
            new_char = cin.get() ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;        
            last_type = INT ;
            temp_token.type = INT ;                  
            temp_char = cin.peek() ;                    
          } // if 
          else if ( temp_char == '_' ) {
            temp_char = cin.get() ;
            mColumn++ ;
            string tempstr = "_";
                  
            temp_char = cin.peek() ;
            while ( temp_char == '_' ) {
              temp_char = cin.get() ;
              mColumn++ ;
              tempstr = tempstr + temp_char ;
              temp_char = cin.peek() ;        
            } // while     
                
            if ( CharIsStr( temp_char, last_type ) ) {
              temp_char = cin.get() ;            
              mColumn++ ;      
              temp_token.value = tempstr + temp_char ;        
              temp_token.type = STRING ;
              last_type = STRING ;          
              temp_char = cin.peek() ;          
            } // if
            else {              
              temp_token.type = UNDEF ;      
              temp_token.value = '_' ;     
              find = true ;                            
            } // else 
        
          } // else if                                  
          else if ( CharIsStr( temp_char, last_type ) )   {
            new_char = cin.get() ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;        
            temp_token.type = STRING ;
            last_type = STRING ;          
            temp_char = cin.peek() ;                    
          } // else if 
          else if (  temp_char == '.' ) {
            new_char = cin.get() ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;   
            temp_char = cin.peek() ; 
            if ( temp_char >= '0' && temp_char <= '9' )  {
              temp_token.type = FLOAT ;
              last_type = FLOAT ;         
            } // if
            else {
              temp_token.type = UNDEF ;
              find = true ;      
            } // else 
                              
          } // else if         
          else if ( CharIsSymbol( temp_char ) ) {
            new_char = cin.get() ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;       
            last_type = SYMBOL ; 
            temp_token.type = SYMBOL ;
            temp_char = cin.peek() ;                        
          } // else if        
          else find = true ;        
        } // if             
        else  {    
          if ( CharIsDigit( temp_char ) &&  last_type == INT ) {
            new_char = cin.get() ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;
            temp_char = cin.peek() ;                 
          } // if       
          else if ( CharIsFloat( temp_char, temp_token.type ) && 
                    ( last_type == FLOAT || last_type == INT ) ) {        
            new_char = cin.get() ;
            last_type = FLOAT ;
            temp_token.type = FLOAT ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;
            temp_char = cin.peek() ;                 
          } // else if                       
          else if ( CharIsStr( temp_char, last_type ) && last_type == STRING ) {
            new_char = cin.get() ;
            mColumn++ ;
            temp_token.value = temp_token.value + temp_char ;
 
            temp_char = cin.peek() ;                 
          } // else if 
          else if ( CharIsSymbol( temp_char ) && last_type == SYMBOL ) {
            string tempstr = temp_token.value + temp_char ;
            if ( tempstr != ">=" && tempstr != "<=" && tempstr != "==" && tempstr != ">=" 
                 && tempstr != "!=" && tempstr != "&&" && tempstr != "||" && tempstr != "+=" 
                 && tempstr != "-=" && tempstr != "*=" && tempstr != "/=" && tempstr != "%=" 
                 && tempstr != "++" && tempstr != "--" && tempstr != ">>" 
                 && tempstr != "<<" )  find = true ;
            else {                      
              new_char = cin.get() ;
              mColumn++ ;
              temp_token.value = temp_token.value + temp_char ;                    
              find = true ;
            } // else
          } // else if      
          else  {
            find = true ;      
          } // else 
        } // else
      } // while
      
    } // else 
    
    mCur_token.value = temp_token.value ;          
    temp_token.column = mColumn ;
    temp_token.line = mLine ;
  } // else 

  if ( temp_token.value == "int" || temp_token.value == "float" 
       || temp_token.value == "char" || temp_token.value == "bool"
       || temp_token.value == "string" || temp_token.value == "void" ) {                          
    temp_token.type = TYPE ;
  } // if 找到命令
  else if ( temp_token.value == "++" || temp_token.value == "--" ) {                          
    temp_token.type = PM ;
  } // else if     
  else if ( temp_token.value == "if" || temp_token.value == "else"
            || temp_token.value == "while" || temp_token.value == "do"
            || temp_token.value == "retrun" ) {      
    temp_token.type = COMMAND ;            
  } // else if 
  else if ( temp_token.type == INT || temp_token.type == FLOAT 
            || temp_token.value == "true" || temp_token.value == "false" ) {                           
    temp_token.type = CONSTANT ;
  } // if 更改Constant type  引號還沒處理""
  else if ( temp_token.value == "+" || temp_token.value == "-"  || temp_token.value == "!" ) 
    temp_token.type = SIGN ;
    
  return temp_token ;
  
} // Scanner::GetToken() 

bool Scanner:: CharIsDigit( char temp_char ) {
  if ( temp_char >= '0' && temp_char <= '9'  ) 
    return true ;    
  return false ;
} // Scanner::CharIsDigit()

bool Scanner:: CharIsUndef( char temp_char ) {
  if (  temp_char == '@' || temp_char == '#' || temp_char == '$'  || temp_char == '`' 
       || temp_char == '~' || temp_char == '\\' ) 
    return true ;
  return false ;
} // Scanner::CharIsUndef()

bool Scanner:: CharIsSymbol( char temp_char )  {
  if ( temp_char == '[' || temp_char == ']' || temp_char == '{' || temp_char == '}' 
       || temp_char == '+' || temp_char == '-' || temp_char == '*' || temp_char == '/' 
       || temp_char == '%' || temp_char == '^' || temp_char == '>' || temp_char == '<' 
       || temp_char == '&' || temp_char == '|' || temp_char == '=' || temp_char == '!' 
       || temp_char == ',' || temp_char == '?' || temp_char == ':' )   
    return true ;    
  return false ;
} // Scanner::CharIsSymbol()

bool Scanner:: CharIsFloat( char temp_char, Type & type  ) {
  if ( ( temp_char >= '0' && temp_char <= '9' ) || temp_char == '.' ) {   
    //    cout << "type  " << type << endl ;
    if ( temp_char == '.' &&  type == FLOAT )  return false ; 
    else return true ;    
  } // if 
  
  return false ;
} // Scanner::CharIsFloat()

bool Scanner:: CharIsSign( char temp_char )  {
  if ( temp_char == '+' || temp_char == '-' ) 
    return true ;    
  return false ;
} // Scanner::CharIsSign()

bool Scanner::CharIsStr( char temp_char, Type & type ) {
  if ( ( temp_char >= 'a' && temp_char <= 'z' ) || ( temp_char >= 'A' && temp_char <= 'Z' ) )
    return true ;
  else if ( type == STRING && temp_char >= '0' && temp_char <= '9' )
    return true ;            
  else if ( type == STRING && temp_char == '_' )
    return true ;
    
  return false ;
} // Scanner::CharIsStr()

void Scanner::Reset() {
  mLine = 1 ;
  mColumn = 0 ;
  mCur_token.line = 1 ;
  mCur_token.column = 0 ;
} // Scanner::Reset()

void Scanner::Reset2() {
  mLine = 0 ;
  mColumn = 0 ;
  mCur_token.line = 1 ;  
  mCur_token.column = 0 ;
} // Scanner::Reset2()


void Scanner:: Clearcur_token() {
  mCur_token.value = "" ;
} // Scanner::Clearcur_token()


