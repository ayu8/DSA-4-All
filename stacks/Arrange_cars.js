// Description

// For sure, the love mobiles will roll again on this summer's street parade. Each year, the organisers decide on a fixed order for the decorated trucks. Experience taught them to keep free a side street to be able to bring the trucks into order.

// The side street is so narrow that no two cars can pass each other. Thus, the love mobile that enters the side street last must necessarily leave the side street first. Because the trucks and the ravers move up closely, a truck cannot drive back and re-enter the side street or the approach street.

// You are given the order in which the love mobiles arrive. Write a program that decides if the love mobiles can be brought into the order that the organisers want them to be


/* SAMPLE INPUT
1
5
5 1 2 4 3 */

/* SAMPLE OUTPUT
YES */

function fun(n,arr){
let s = []
let num = 1;
for(let i=0;i<n;i++){
while(num==s[s.length-1] && s.length!=0){
s.pop()
num++;
    
}
if(arr[i]==num){
    num++
}else{
    s.push(arr[i])
}

}  


while(s.length!=0 && s[s.length-1]==num){
num++;
s.pop()
}
    
num--
if(num==n){
    console.log("YES")
}    else{
    console.log("NO")
}
   
}
