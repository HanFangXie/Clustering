#!/bin/bash

for VAR in 66d0ed7f-eeef-4a60-b009-48482a6381c5 b108ce61-c6c1-4e78-bc46-0cf69dff8871 496b4c32-cbd0-4f85-a32b-dff7010cca06 82eb22f6-a671-4411-89cf-df524ce551de 2c93d33b-42de-47dc-8294-7011e1405008 0f03cb63-7af7-4f42-9e93-a487acca1107 8f337826-804a-4a3b-84bc-185efbfba659 3cf2499c-087b-4c73-bbb3-356c2a5dfdb8 5b590d54-89c1-4a71-a5c9-58a38c3d8b5d abd34372-2c71-4568-b7c3-4e523fe5fe40 7662aa34-e8e5-46a1-b6fa-cc7bb9ccfa39 f96483cb-c034-4727-a0db-1308104bb93c b263bc19-552a-4a88-8d64-0c33f9722012 a85b4fd0-050f-40a7-b57a-b55101df5564 bf28a9f2-cf94-4d24-ab37-613257e9727f 7318a36a-b61b-4309-a84e-ac08bff03f5d c280a978-363a-4dda-9f8a-c4ec54136e53
do
    #`samweb list-definition-files prodmarley_nue_spectrum_radiological_timedep_hudepohl_11.2M_3perevent_dune10kt_1x2x6_mcc11 | grep $VAR`
    file=`samweb list-definition-files prodmarley_nue_spectrum_radiological_timedep_hudepohl_11.2M_3perevent_dune10kt_1x2x6_mcc11 | grep $VAR`
    loc=`samweb locate-file $file`
    echo $loc/$file
done
