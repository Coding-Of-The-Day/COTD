<?php
fscanf(STDIN, "%d %d", $n, $m); // 1번째, 끊어진 기타줄수 // 브랜드 수

$package = array();
$single = array();
for ($i = 0; $i < $m; $i++) { // 2번째부터 6줄의 패키지 가격 // 낱개의 가격
    fscanf(STDIN, "%d %d", $package[], $single[]); // 각 브랜드의 패키지 가격과 낱개의 가격이 공백으로 구분하여 주어진다. 가격은 0보다 크거나 같고, 1,000보다 작거나 같은 정수이다.
}

$low_package = min($package);
$low_single = min($single);

$result = 0;
while ($n > 0) {
    if ((($n * $low_single) < $low_package) && $n < 6) {
        $result += $low_single;
        $n -= 1;
    } else {
        $result += $low_package;
        $n -= 6;
    }
}

fprintf(STDOUT, "%d", $result);

