
module helloworldfpga(

    input  wire A,
    input  wire B,
    input  wire C,
    input  wire D,
    
    output  wire a,
    output  wire b,
    output  wire c,
    output  wire d,
    output  wire e,
    output  wire f,
    output  wire g,
    output  wire W,
    output  wire X,
    output  wire Y,
    output  wire Z,
    );
   // assign U=0;
    //assign V=0;
    //assign W=0;
    
    always @(*)
    begin
W= (!A&&B&&D) || (!A&&B&&C) || (A&&!B&&!C);
X= (!A&&!B&&D) || (!A&&!B&&C) || (!A&&B&&!C&&!D) || (A&&!B&&!C&&D);
Y= (!A&&!C&&!D) || (!A&&C&&D) || (A&&!B&&!C&&!D);
Z= (!A&&!D) || (A&&!B&&!C&&!D);
a= (!W&&X&&!Y&&!Z);
b= (!W&&X&&!Y&&Z) || (!W&&X&&Y&&!Z) || (W&&X&&!Y&&!Z);
c= (W&&X&&!Y&&!Z);
d= (!W&&X&&!Y&&!Z) || (!W&&X&&Y&&Z) || (W&&!X&&Y&&!Z);
e= (!W&&Y&&Z) || (!W&&X&&!Y) || (W&&!X&&!Y&&Z);
f= (!W&&Y&&Z);
g= (!W&&X&&Y&&Z) || (W&&X&&!Y&&!Z);
    end
    endmodule
