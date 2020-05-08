
void serialEvent(Serial port){   
   String inData = port.readStringUntil('\n');  
   
   if (inData.charAt(0) == 'Q'){          // leading 'Q' means time between beats in milliseconds
     inData = inData.substring(1);        // cut off the leading 'Q'
     inData = trim(inData);               // trim the \n off the end
     IBI = int(inData);                   // convert ascii string to integer IBI 
     pulse = true;                        // set the pulse flag
     return;     
   }
   
   if (inData.charAt(0) == 'S'){          // leading 'S' means sensor data
     inData = inData.substring(1);        // cut off the leading 'S'
     inData = trim(inData);               // trim the \n off the end
     ppgY = int(inData);                  // convert the ascii string to ppgY
   return;     
   }   
}// END OF SERIAL EVENT
