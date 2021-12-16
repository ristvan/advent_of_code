from util import read_file

LITERAL_VALUE = 4


def translate_to_binary(hex_packet):
    translator = {
        "0": "0000",
        "1": "0001",
        "2": "0010",
        "3": "0011",
        "4": "0100",
        "5": "0101",
        "6": "0110",
        "7": "0111",
        "8": "1000",
        "9": "1001",
        "A": "1010",
        "B": "1011",
        "C": "1100",
        "D": "1101",
        "E": "1110",
        "F": "1111"
    }
    return "".join([translator[character] for character in hex_packet])


class Literal:
    def __init__(self, value):
        self._value = value

    def get_value(self):
        return self._value

    def get_version_summary(self):
        return 0


class Operator:
    def __init__(self, length: int):
        self._length = length
        self._sub_packets = list()

    def __len__(self):
        return self._length

    def add_sub_packet(self, packet):
        self._sub_packets.append(packet)

    def __iter__(self):
        for sub_packet in self._sub_packets:
            yield sub_packet

    def get_version_summary(self):
        return sum([sub_packet.get_version_summary() for sub_packet in self._sub_packets]) if self._sub_packets else 0


class Packet:
    def __init__(self, version, type):
        self._version = version
        self._type = type
        self._item = None

    def get_version(self):
        return self._version

    def get_type(self):
        return self._type

    def get_item(self):
        return self._item

    def set_item(self, item):
        self._item = item

    def get_version_summary(self):
        return self._version + (self._item.get_version_summary() if self._item else 0)


class PacketDecoder:
    def __init__(self, encoded_packet):
        self._encoded_packet = encoded_packet
        self._binary_format = ""

    def decode(self):
        self._binary_format = translate_to_binary(self._encoded_packet)
        return self._parse_packet()

    def _parse_packet(self):
        if len(self._binary_format) < 10:
            return Packet(0, 0)
        version = int(self._binary_format[0:3], 2)
        type_id = int(self._binary_format[3:6], 2)
        packet = Packet(version, type_id)
        self._binary_format = self._binary_format[6:]
        if type_id == LITERAL_VALUE:
            packet.set_item(self._hande_literal_value())
        else:
            packet.set_item(self._handle_operator())
        return packet

    def _hande_literal_value(self):
        number_as_string = ""
        while True:
            number_part = self._binary_format[0:5]
            self._binary_format = self._binary_format[5:]
            number_as_string += number_part[1:]
            if number_part[0] == "0":
                break
        return Literal(int(number_as_string, 2))

    def _handle_operator(self):
        length_type_id = int(self._binary_format[0])
        self._binary_format = self._binary_format[1:]

        sub_packet_length = 11 if length_type_id == 1 else 15
        length_ = self._binary_format[0:sub_packet_length]
        length = int(length_, 2)
        self._binary_format = self._binary_format[sub_packet_length:]
        operator = Operator(length)
        for _ in range(length):
            operator.add_sub_packet(self._parse_packet())

        return operator


def solve():
    lines_of_file = read_file("d16_packet_decoder/input.txt")
    x = PacketDecoder(lines_of_file[0]).decode()

    print("Day 16")
    print(f"  - Part 1: {x.get_version_summary()}")