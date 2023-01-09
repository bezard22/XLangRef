#!/bin/bash
# utilities/newProj.sh

function setup() {
    # language directory
    mkdir $proj/$1
    
    # run script
    touch $proj/$1/run.sh
    echo -e "#!/bin/bash\n# $proj/$1/run.sh" >> $proj/$1/run.sh
    chmod +x $proj/$1/run.sh

    # build script
    mkdir $proj/$1/build
    touch $proj/$1/build/build.sh
    echo -e "#!/bin/bash\n# $proj/$1/build/build.sh" >> $proj/$1/build/build.sh
    chmod +x $proj/$1/build/build.sh
    
    # src directory
    mkdir $proj/$1/src
}


proj=$1

# project directory
mkdir $proj

# run script
cp ./utilities/genericRun.sh $proj/run.sh
sed -i "s#<path>#$proj/run.sh#" $proj/run.sh
chmod +x $proj/run.sh

# runAll script
cp ./utilities/genericRunAll.sh $proj/runAll.sh
sed -i "s#<path>#$proj/runAll.sh#" $proj/runAll.sh
chmod +x $proj/runAll.sh

# build script
cp ./utilities/genericBuild.sh $proj/build.sh
sed -i "s#<path>#$proj/build.sh#" $proj/build.sh
chmod +x $proj/build.sh

# README
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