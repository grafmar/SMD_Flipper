plateXX=20;
plateYY=20;
thickness=1;
foamThickness=2;
$fs=0.5;
$fa=2;

union(){
    difference() {
        translate([-plateXX/2-thickness,5,-(thickness+foamThickness)])cube([plateXX+2*thickness,plateYY+2*thickness,thickness+foamThickness]);
        translate([-plateXX/2,5+thickness,-foamThickness])cube([plateXX,plateYY,thickness+foamThickness]);
    }
    
    difference(){
        translate([-3-plateXX/2-thickness,5,-(thickness+foamThickness)])cube([3,plateYY+2*thickness,2*(thickness+foamThickness)]);
        //14, 8
        translate([-plateXX/2-thickness,8,0])rotate([0,90,0])cylinder(d=1,h=3*3,center=true);
        translate([-plateXX/2-thickness,14,0])rotate([0,90,0])cylinder(d=1,h=3*3,center=true);
    }
}
