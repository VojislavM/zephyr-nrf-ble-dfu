/* Vojislav milivojevic
 * https://github.com/VojislavM
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <init.h>

#include <img_mgmt/img_mgmt.h>
#include <os_mgmt/os_mgmt.h>
#include <mgmt/mcumgr/smp_bt.h>

#include <logging/log.h>
LOG_MODULE_REGISTER(init_dfu);


static int bt_smp_init(const struct device *dev)
{
	ARG_UNUSED(dev);
	int err = 0;

	img_mgmt_register_group();
	os_mgmt_register_group();

	err = smp_bt_register();

	if (err) {
		LOG_ERR("SMP BT register failed (err: %d)", err);
	}

	return err;
}

SYS_INIT(bt_smp_init, APPLICATION, CONFIG_APPLICATION_INIT_PRIORITY);
