#include "Rte_Type.h"


const Interface_BOOLEAN DigOutParam_Inst1_IsHighPolarity_IsHighPoarity_parm = 0;
const Interface_BOOLEAN DigOutParam_Inst1_ChEnable_ChEnable_Parm = 0;


Std_ReturnType Rte_Read_IOHwAbSDigOut_Inst1_IsHighPolarity_IsHighPoarity_parm (Interface_BOOLEAN* data)
{
   Std_ReturnType return_value = E_NOT_OK;
   if (NULL_PTR == data){
         return_value = E_NOT_OK;
   }

   else{
      *data = DigOutParam_Inst1_IsHighPolarity_IsHighPoarity_parm;
      return_value = E_OK;
   }
   return return_value;
}

Std_ReturnType Rte_Read_IOHwAbSDigOut_Inst1_ChEnable_ChEnable_Parm (Interface_BOOLEAN* data)
{
   Std_ReturnType return_value = E_NOT_OK;
   if (NULL_PTR == data){
         return_value = E_NOT_OK;
   }

   else{
      *data = DigOutParam_Inst1_ChEnable_ChEnable_Parm;
      return_value = E_OK;
   }
   return return_value;
}



