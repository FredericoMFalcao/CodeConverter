<?php $modules=[];foreach(scandir("app_modules") as $file) if(!in_array($file, [".",".."]) && is_dir($file)) $modules[]=$file; ?>
