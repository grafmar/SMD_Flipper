servoOffset=57;
servoScrewOffset=27.3;
servoScrewDia=1.5;
servoWidth=22.5;
servoThickness=11.8;
servoAxisOffset=22.5/2-5.9;
clearance=0.5;
plateOuterDistance=28;

HousingInnerHeight=25;
HousingInnerWidth=92;
HousingInnerLength=72;
HousingRoundness=5;
thickness=2;


plateXX=20;
plateYY=20;
plateThickness=1;
foamThickness=2;
$fs=0.5;
$fa=2;

// Housing
housing();

// Plate support
translate([-plateXX/2,-plateOuterDistance,0])cube([plateXX,2*plateOuterDistance,servoThickness/2-plateThickness-foamThickness]);

// Servo mount
servoMount();
mirror([1,0,0]) servoMount();
module servoMount(){
    for(i=[-1,1])translate([servoOffset/2-7/2,i*servoScrewOffset/2+servoAxisOffset,servoThickness/2])difference(){
        cube([7,servoScrewOffset-servoWidth-clearance,servoThickness],center=true);
        rotate([0,90,0])cylinder(d=servoScrewDia,h=8,center=true);
    }
}

module housing() {
    xOffset=(HousingInnerWidth-(HousingRoundness-thickness))/2;
    yOffset=(HousingInnerLength-(HousingRoundness-thickness))/2;
    PcbTop=-15;
    
    difference() {
        hull() for(ix=[-1,1])for(iy=[-1,1])translate([ix*xOffset,iy*yOffset,-HousingInnerHeight])cylinder(d=HousingRoundness,h=HousingInnerHeight);
        
        // inner
        hull() for(ix=[-1,1])for(iy=[-1,1])translate([ix*xOffset,iy*yOffset,-HousingInnerHeight-thickness])cylinder(d=HousingRoundness-thickness,h=HousingInnerHeight);
            
        // Servo cable holes
        for(ix=[-1,1])hull()for(yy=[0,10])translate([ix*(servoOffset/2+10),servoAxisOffset-servoWidth/2-3/2+yy,0])cylinder(d=3,h=thickness*3,center=true);
            
        // USB Hole
        hull()for(ix=[-1,1])for(iy=[-1,1])translate([ix*10/2+2.54/2,yOffset,iy*7/2+PcbTop+7])rotate([90,0,0])
            cylinder(d=4,h=3*thickness,center=true);
        
        // Button
        translate([HousingInnerWidth/2-15,-(HousingInnerLength/2-10),0])cylinder(d=7,h=3*thickness,center=true);
    }
    
    // screws
    screwXX=91/2-1.5;
    screwYY=70/2-1.5;
    pos=[
    [-(screwXX-1.2) ,(screwYY-1.9)],
    [(screwXX-3)    ,(screwYY-2.2)],
    [-(screwXX-2.5) ,-(screwYY-3.45)],
    [(screwXX-2.7)  ,-(screwYY-1.5)]];
    for(i=[0:3])translate([pos[i][0],pos[i][1],PcbTop])difference(){
        cylinder(d=6,h=-PcbTop-thickness);
        translate([0,0,-3])cylinder(d=3,h=-PcbTop-thickness);
    }
}




//plate();
module plate() {
thickness=plateThickness;
translate([0,0,servoThickness/2])union(){
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
}