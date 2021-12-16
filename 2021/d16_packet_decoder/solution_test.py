import unittest

from d16_packet_decoder.solution import LITERAL_VALUE, Packet, PacketDecoder


class PacketDecoderTestCase(unittest.TestCase):
    def test_parsing_literal_value(self):
        encoded_packet = "D2FE28"
        decoded_packet = PacketDecoder(encoded_packet).decode()
        self.assertIsInstance(decoded_packet, Packet)
        self.assertEqual(LITERAL_VALUE, decoded_packet.get_type())
        self.assertEqual(6, decoded_packet.get_version())
        self.assertEqual(2021, decoded_packet.get_item().get_value())

    def test_parsing_an_operator(self):
        encoded_packet = "EE00D40C823060"
        decoded_packet = PacketDecoder(encoded_packet).decode()
        self.assertIsInstance(decoded_packet, Packet)
        self.assertNotEqual(LITERAL_VALUE, decoded_packet.get_type())
        self.assertEqual(7, decoded_packet.get_version())

    def test_summary_of_version_numbers(self):
        testcases = [
            ("D2FE28", 6),
            ("EE00D40C823060", 14),
            ("8A004A801A8002F478", 16),
            ("620080001611562C8802118E34", 12),
            ("C0015000016115A2E0802F182340", 23),
            ("A0016C880162017C3686B18A3D4780", 31)
        ]
        for encoded_packet, expected_summary in testcases:
            decoded_packet = PacketDecoder(encoded_packet).decode()
            self.assertEqual(expected_summary, decoded_packet.get_version_summary())


if __name__ == '__main__':
    unittest.main()
