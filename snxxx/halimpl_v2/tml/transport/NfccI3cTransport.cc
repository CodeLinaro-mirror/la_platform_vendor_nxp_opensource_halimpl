/******************************************************************************
 *  Copyright 2024-2026 NXP
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 ******************************************************************************/

#include <NfccI3cTransport.h>
#include <errno.h>
#include <phNxpLog.h>

/*******************************************************************************
**
** Function         Read
**
** Description      Reads requested number of bytes from NFCC device into given
**                  buffer
**
** Parameters       pDevHandle       - valid device handle
**                  pBuffer          - buffer for read data
**                  nNbBytesToRead   - number of bytes requested to be read
**
** Returns          numRead   - number of successfully read bytes
**                  -1        - read operation failure
**
*******************************************************************************/
int NfccI3cTransport::Read(void* pDevHandle, uint8_t* pBuffer,
                           int nNbBytesToRead) {
  int ret_Read;

  if (NULL == pDevHandle || NULL == pBuffer) {
    return -1;
  }

  memset(pBuffer, 0x00, nNbBytesToRead);
  ret_Read = read((int)(intptr_t)pDevHandle, pBuffer, nNbBytesToRead);
  if (ret_Read <= 0) {
    NXPLOG_TML_E(
        "%s No of bytes requested to read: %d, No of bytes read %d and "
        "errno : %x", __func__, nNbBytesToRead, ret_Read, errno);
    return -1;
  }
  return ret_Read;
}
