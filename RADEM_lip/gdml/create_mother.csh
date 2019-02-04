set count=1

while( $count <= 104 ) 

	#sed -i '$ a <physvol>' mother.gdml
        #sed -i '$ a <file name="gdml/Sil'$count'.gdml"/>' mother.gdml
        #sed -i '$ a <positionref ref="center"/>' mother.gdml
        #sed -i '$ a <rotationref ref="identity"/>' mother.gdml
        #sed -i '$ a </physvol>' mother.gdml

#<physvol>
#<file name="gdml/Sil1.gdml"/>
#<positionref ref="center"/>
#<rotationref ref="identity"/>
#</physvol>

	@ count++
end


foreach file (RDM*.gdml)

	echo $file

        set object = `echo $file | awk '{print substr($file,14,1)}'`
	if ( $object == "c" ) then 
        	sed -i '$ a <physvol>' mother.gdml
        	sed -i '$ a <file name="gdml/'$file'"/>' mother.gdml
        	sed -i '$ a <positionref ref="center"/>' mother.gdml
        	sed -i '$ a <rotationref ref="identity"/>' mother.gdml
	        sed -i '$ a </physvol>' mother.gdml

	endif
end

