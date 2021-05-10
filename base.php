<?php $modules=[];foreach(scandir("app_modules") as $file) if(!in_array($file, [".",".."]) && is_dir("app_modules/$file")) $modules[]=$file; ?>
