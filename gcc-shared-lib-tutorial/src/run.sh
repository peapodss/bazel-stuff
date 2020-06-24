#set -ex

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"



export LD_LIBRARY_PATH=$SCRIPT_DIR/mybin/myfunctions:$LD_LIBRARY_PATH
$SCRIPT_DIR/mybin/use-shared-library

echo "==========================="
echo "using dlopen"
echo "==========================="

$SCRIPT_DIR/mybin/dynamic-library-loader