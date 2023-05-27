/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let lengthoflastword = 0;
    for ( let i = s.length - 1 ; i >= 0 ; i-- ){
        if ( s.charAt(i) == ' '){
            if ( lengthoflastword != 0 ) break;
            continue;
        }
        lengthoflastword++;
    }
    return lengthoflastword;
};