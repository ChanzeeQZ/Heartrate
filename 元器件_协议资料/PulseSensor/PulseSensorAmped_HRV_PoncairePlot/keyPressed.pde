



void keyPressed(){
// take a picture of the screen by pressign the s key 
 if (key == 's' || key =='S'){
  saveFrame("HRV-####.jpg");      // take a shot of that!
 }
// clear the Poncaire plot arrays and clear the phase space by pressing c key 
 if (key == 'c'){
   for (int i=numPoints-1; i>=0; i--){  // 
      beatTimeY[i] = 0;
      beatTimeX[i] = 0;
    }
 }
}  // END OF KEYPRESSED
