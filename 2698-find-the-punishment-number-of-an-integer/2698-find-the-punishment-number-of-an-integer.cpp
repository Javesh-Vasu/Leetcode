class Solution {
public:
    int punishmentNumber(int n) {
        int punishmentNumber = 1;
        for ( int i = 2 ; i <= n ; i++){
            if (isValidForPunishment(i)){
               
                punishmentNumber += i*i;
            }
        }
        //isValidForPunishment(235);
        return punishmentNumber;
    }
    
    bool isValidForPunishment( int i ){
        int square = i*i;
        return helperForisValid( i,square,10 );
    }
    
    bool helperForisValid(int originalNumber, int square, int tenthPower){
       
        if ( originalNumber == square) return true;
        if  (originalNumber < 0) return false;
        
        while( square/tenthPower > 0 ){
            int reduce = square%tenthPower;
            originalNumber -= reduce;
            square /= tenthPower;
            if ( helperForisValid(originalNumber,square,10) ) return true;
            if ( originalNumber < 0 ) return false;
            originalNumber += reduce;
            square = square*tenthPower + reduce;
            tenthPower = tenthPower*10;
        }
        return false;
    }
};