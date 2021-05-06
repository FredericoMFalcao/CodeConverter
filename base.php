<?php $modules=[];foreach(scandir("modules") as $file) if(!in_array($file, [".",".."])) $modules[]=$file; ?>
