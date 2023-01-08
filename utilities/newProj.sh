#!/bin/bash
# utilities/newProj.sh

function setup() {
    mkdir $proj/$1
    touch $proj/$1/run.sh
    echo -e "#!/bin/bash\n# $proj/$1/run.sh" >> $proj/$1/run.sh
    chmod +x $proj/$1/run.sh
    mkdir $proj/$1/src
}

proj=$1
mkdir $proj
cp ./utilities/genericRun.sh $proj/run.sh
sed -i "s#<path>#$proj/run.sh#" $proj/run.sh
chmod +x $proj/run.sh
cp ./utilities/genericRunAll.sh $proj/runAll.sh
sed -i "s#<path>#$proj/runAll.sh#" $proj/runAll.sh
chmod +x $proj/runAll.sh
cp ./utilities/genericREADME.md $proj/README.md
sed -i "s/<project>/$proj/" $proj/README.md

setup "c"
setup "c#"
setup "c++"
setup "go"
setup "java"
setup "javascript"
setup "python"
setup "ruby"
setup "rust"
setup "scala"
setup "typescript"