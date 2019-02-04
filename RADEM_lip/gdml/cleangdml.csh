foreach file (*.gdml)
       	echo $file
	set split  = ($file:as/./ /)
	echo $split[1]
	sed -i "s|"$split[1].stl"|"$split[1]"|g" $split[1].gdml

	set volname = `grep -m 1 -i "Volume name" $file`
        set physname = `grep -m 1 -i "physvol name" $file`
	set worldref = `grep -m 1 -i "world ref" $file`
	set volname2 = `grep -m 2 -n -i "Volume name" $file | tail -n1 `
	set numb1 = `grep -m 2 -n -i "Volume name" $file | tail -n1 | cut -f1,1 -d:`
	echo $numb1[1]
	set numb2 = `grep -m 2 -n -i "Volume>" $file | tail -n1 | cut -f1,1 -d:`
	echo $numb2
	sed -i -e ''$numb1[1]','$numb2[1]'d' $file 
	#echo $volname2

	set nlines = `echo $volname | wc -m`
	#echo $nlines
	set object = `echo $volname | awk '{print substr($file,15,20)}'`
        set object2 = `echo $physname | awk '{print substr($file,16,21)}'`
	set object3 = `echo $worldref | awk '{print substr($file,13,22)}'`
	#set object4 =  `echo $volname2 | awk '{print substr($file,2,'$nlines')}'`
	#echo $object4

	if ($nlines == "36") then
		echo $nlines
        	set object = `echo $volname | awk '{print substr($file,15,19)}'`
	        set object2 = `echo $physname | awk '{print substr($file,16,20)}'`
	        set object3 = `echo $worldref | awk '{print substr($file,13,21)}'`
	endif

	set worldchanger = "$split[1]"	
	sed -i "s|"$object"|"$split[1]"|g" $split[1].gdml
	sed -i "s|"$object2"|"$split[1]_phys"|g" $split[1].gdml
	sed -i "s|"$object3"|"$worldchanger"|g" $split[1].gdml
	
	#set nline = `grep -n "<materials>" Sil1.gdml`
	#set nlines = ($nline:as/:/ /)

	#echo $nlines[1	echo $nlines[1]]
	#sed -i ''$nvar' i\  '$nvar'' Sil1.gdml

   # <material name="Si" Z="14">
   #   <D value="2.336" unit="g/cm3" />
   #   <atom type="A" value="28.0855" />
   # </material>


end
