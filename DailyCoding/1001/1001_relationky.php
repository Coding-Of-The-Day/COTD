<?php
// Request Input
fscanf(STDIN, "%d %d", $a, $b);

$result = $a - $b;

// Response Output
fprintf(STDOUT, "%d", $result);